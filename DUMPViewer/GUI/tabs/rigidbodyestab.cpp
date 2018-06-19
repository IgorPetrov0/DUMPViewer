 #include "rigidbodyestab.h"
#include "ui_rigidbodyestab.h"

rigidBodyesTab::rigidBodyesTab(QTabWidget *parent) :
    dTabBar(parent),
    ui(new Ui::rigidBodyesTab)
{
    ui->setupUi(this);
    setCurrentBody(NULL);
    createTab();
    connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(addSlot()));
    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteSlot()));
    connectAll();
}
/////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::connectAll(){
    connect(ui->rigidBodiesList,SIGNAL(itemSelectionChanged()),this,SLOT(bodyChangeSlot()));
    connect(ui->rigidBodiesList,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(nameChangedSlot()));
    connect(ui->massSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassSlot(double)));
    connect(ui->massCenterXSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    connect(ui->massCenterYSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    connect(ui->massCenterZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    connect(ui->typeComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setTypeSlot(int)));
}
////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::disconnectAll(){
    disconnect(ui->rigidBodiesList,SIGNAL(itemSelectionChanged()),this,SLOT(bodyChangeSlot()));
    disconnect(ui->rigidBodiesList,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(nameChangedSlot()));
    disconnect(ui->massSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassSlot(double)));
    disconnect(ui->massCenterXSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    disconnect(ui->massCenterYSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    disconnect(ui->massCenterZSpinBox,SIGNAL(valueChanged(double)),this,SLOT(setMassCenterSlot()));
    disconnect(ui->typeComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setTypeSlot(int)));
}
/////////////////////////////////////////////////////////
rigidBodyesTab::~rigidBodyesTab()
{
    delete ui;
}
//////////////////////////////////////////////////////////////
void rigidBodyesTab::createTab(){
    addWidget(ui->showRigidBodyRadioButton);
    addWidget(ui->rigidBodyesGroup);
    addWidget(ui->typeComboBox);
    addWidget(ui->meshInfoWidget);
    addWidget(ui->massGroup);
    ui->meshInfoWidget->setOriginSize();

    ui->typeComboBox->addItem(tr("Movable"),QVariant(RIGID_BODY_MOVABLE));
    ui->typeComboBox->addItem(tr("Static"),QVariant(RIGID_BODY_STATIC));

    configureSourceComboBox();
}
////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::configureSourceComboBox(){
    ui->meshSourceComboBox->clear();
    if(app!=NULL){
        if(app->currentObject()!=NULL){
            ui->meshSourceComboBox->addItem(tr("File"));
            if(app->currentObject()->mainMeshExsist()){
                ui->meshSourceComboBox->addItem(tr("Main mesh"));
            }
            unsigned int size=app->currentObject()->LODsSize();
            for(unsigned int n=0;n!=size;n++){
                ui->meshSourceComboBox->addItem(tr("from LOD")+QString::number(n+1));
            }
            ui->meshSourceComboBox->setCurrentIndex(0);
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::updateInfoSlot(){
    disconnectAll();
    configureSourceComboBox();
    updateList();
    editabelPhisycObject *object=app->currentObject()->getPhisycObject();
    if(object!=NULL){
        editabelRigidBody *body=object->getRigitBody(ui->meshSourceComboBox->currentIndex());
        if(body!=NULL){
            switch(body->getType()){
                case(RIGID_BODY_MOVABLE):{
                    ui->typeComboBox->setCurrentIndex(0);
                    break;
                }
                case(RIGID_BODY_STATIC):{
                    ui->typeComboBox->setCurrentIndex(1);
                    break;
                }
            }
        }
    }
    connectAll();
}
///////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::addSlot(){
    editabelRigidBody *body=NULL;
    switch(ui->meshSourceComboBox->currentIndex()){
        case(0):{//файл
            QString name=dFileDialog::getOpenFileName(app,tr("Open mesh file"),app->currentPath(),app->modelFilter());
            if(!name.isEmpty()){
                editabelGraphicObject gObject;
                QFileInfo fi(name);
                gObject.setName(fi.fileName().toStdString());
                if(!app->loadGraphicObject(name,&gObject)){
                    QMessageBox box(parentWidget());
                    box.setWindowTitle(tr("Error"));
                    box.setIcon(QMessageBox::Warning);
                    box.setDefaultButton(QMessageBox::Ok);
                    box.setText(app->getLastError());
                    box.exec();
                    return;
                }
                body=new editabelRigidBody(&gObject,MESH_ORIGINAL);
            }
            break;
        }
        case(1):{//mainMesh
            body=new editabelRigidBody(app->currentObject()->getMainMesh(),MESH_MAIN_MESH);
            break;
        }
        case(2):{//LOD1
            body=new editabelRigidBody(app->currentObject()->getLod(0),MESH_LOD1);
            body->setSource(MESH_LOD1);
            break;
        }
        case(3):{//LOD2
            body=new editabelRigidBody(app->currentObject()->getLod(1),MESH_LOD2);
            body->setSource(MESH_LOD2);
            break;
        }
        case(4):{//LOD3
            body=new editabelRigidBody(app->currentObject()->getLod(2),MESH_LOD3);
            body->setSource(MESH_LOD3);
            break;
        }
        case(5):{//LOD4
            body=new editabelRigidBody(app->currentObject()->getLod(3),MESH_LOD4);
            body->setSource(MESH_LOD4);
            break;
        }
    }
    if(body!=NULL){
        app->currentObject()->addRigiBody(body);
        updateList();
        //ui->meshInfoWidget->calculateMeshParameters(body->getMeshPointer());
        setCurrentBody(body);
        ui->typeComboBox->setEditable(true);
    }
}
///////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::updateList(){
    unsigned int size=app->currentObject()->rigidBodyesCount();
    ui->rigidBodiesList->clear();
    for(unsigned int n=0;n!=size;n++){
        QListWidgetItem *item=new QListWidgetItem();
        item->setData(Qt::UserRole,n);
        //item->setText(QString::fromStdString(app->currentObject()->getPhisycObject()->getRigitBody(n)->getMeshPointer()->getName()));
        item->setFlags(item->flags()|Qt::ItemIsEditable);
        ui->rigidBodiesList->addItem(item);
    }
    ui->rigidBodiesList->setCurrentItem(ui->rigidBodiesList->item(size-1));
    //setCurrentBody(app->currentObject()->getPhisycObject()->getRigitBody(ui->rigidBodiesList->currentItem()->data(Qt::UserRole).toInt()));
}
/////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::deleteSlot(){
    app->currentObject()->getPhisycObject()->removeRigidBody(currentBody);
    setCurrentBody(NULL);
    updateList();
}
//////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::bodyChangeSlot(){
    QListWidgetItem *item=ui->rigidBodiesList->currentItem();
    if(item!=NULL){
        setCurrentBody(app->currentObject()->getPhisycObject()->getRigitBody(item->data(Qt::UserRole).toInt()));
        if(currentBody!=NULL){
            disconnectAll();
            //ui->meshInfoWidget->calculateMeshParameters(currentBody->getMeshPointer());
            ui->massSpinBox->setValue(currentBody->getMass());
            ui->massCenterXSpinBox->setValue(currentBody->getMassCenter().x());
            ui->massCenterYSpinBox->setValue(currentBody->getMassCenter().y());
            ui->massCenterZSpinBox->setValue(currentBody->getMassCenter().z());
            switch(currentBody->getType()) {
                case(RIGID_BODY_MOVABLE):{
                    ui->typeComboBox->setCurrentIndex(0);
                    break;
                }
                case(RIGID_BODY_STATIC):{
                    ui->typeComboBox->setCurrentIndex(1);
                    break;
                }
            }
            connectAll();
        }
    }
    if(currentBody!=NULL){
        ui->typeComboBox->setEnabled(true);
    }
    else{
        ui->typeComboBox->setEnabled(false);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::nameChangedSlot(){
    //currentBody->getMeshPointer()->setName(ui->rigidBodiesList->currentItem()->text().toStdString());
}
////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::setMassSlot(double value){
    currentBody->setMass(value);
}
//////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::setMassCenterSlot(){
    vector3 center;
    center.setX(ui->massCenterXSpinBox->value());
    center.setY(ui->massCenterYSpinBox->value());
    center.setZ(ui->massCenterZSpinBox->value());
    currentBody->setMassCenter(center);
}
//////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::setTypeSlot(int type){

    switch(type){
        case(0):{
            currentBody->setType(RIGID_BODY_MOVABLE);
            break;
        }
        case(1):{
            currentBody->setType(RIGID_BODY_STATIC);
            break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rigidBodyesTab::setCurrentBody(rigidBody *body){
    currentBody=body;
    if(body!=NULL){
        ui->typeComboBox->setEnabled(true);
    }
    else{
        ui->typeComboBox->setDisabled(true);
    }
}
