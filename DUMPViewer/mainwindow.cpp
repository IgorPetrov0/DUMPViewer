#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view=new viewWindow(this);

}
//////////////////////////////////////////////////////
MainWindow::~MainWindow()
{  
    delete ui;
    delete progressBar;
    delete statusLable;
    delete tPanel;
    core->deleteCurrentObject();
    delete view;
}
////////////////////////////////////////////////////////
void MainWindow::connections(){
    connect(ui->actionNew,SIGNAL(triggered(bool)),this,SLOT(newGameObjectSlot()));
    connect(ui->actionClose,SIGNAL(triggered(bool)),this,SLOT(closeCurrentObjectSlot()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(saveGameObjectSlot()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openGameObjectSlot()));
    connect(this,SIGNAL(objectLoaded()),tPanel,SLOT(updateInfoSlot()));
    connect(core,SIGNAL(changed()),this,SLOT(someChanged()));
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::openModel(){

    //Оставлено для образца

//    compiller->createEmptyObject("D:\\Projects\\DUMPViewer\\models\\lectnica.obj");//создаем пустой объект
//    if(compiller->addGraphicMesh("D:\\Projects\\DUMPViewer\\models\\lectnica.obj")){//загружаем меш
//        if(view->loadModel(compiller->getCurrentObject()->getMainMesh())){
//            return;
//        }
//    }
//    QMessageBox box(this);
//    box.setText(tr("Error open model."));
//    box.setStandardButtons(QMessageBox::Ok);
//    box.setIcon(QMessageBox::Critical);
//    box.exec();

//    QString modelFileName=QFileDialog::getOpenFileName(this,tr("Open model file"),lastOpenDir,modelFilter);
//    if(!modelFileName.isEmpty()){
//        compiller->createEmptyObject(QFileInfo(modelFileName).baseName());//создаем пустой объект
//        if(compiller->addGraphicMesh(modelFileName)){//загружаем меш
//            if(view->loadModel(compiller->getCurrentObject()->getMainMesh())){
//                return;
//            }
//        }
//        QMessageBox box(this);
//        box.setText(tr("Error open model."));
//        box.setStandardButtons(QMessageBox::Ok);
//        box.setIcon(QMessageBox::Critical);
//        box.exec();
//    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::keyPressEvent(QKeyEvent *event){
    view->keyPressed(event->key());
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::resizeEvent(QResizeEvent *event){
    setWidgetsGeometry();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setWidgetsGeometry(){
    int pX,pY,w,h;
    int upY=ui->menuBar->geometry().height()+ui->mainToolBar->geometry().height();//у-координата после меню и тулбара

    //считаем геометрию панели инструментов
    pX=this->width()-tPanel->width();
    pY=upY;
    w=tPanel->geometry().width();
    h=this->height()-upY-ui->statusBar->height()-5;
    tPanel->setGeometry(pX,upY,w,h);

    //считаем геометрию видового окна
    pX=1;
    pY=upY;
    w=this->width()-tPanel->width()-5;
    view->setGeometry(pX,pY,w,h);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::createStatusBar(){
    QLineEdit *edit=new QLineEdit;
    edit->setEnabled(false);
    ui->statusBar->addPermanentWidget(statusLable);
    ui->statusBar->addPermanentWidget(edit);
    ui->statusBar->addPermanentWidget(progressBar);
    progressBar->show();
    progressBar->setRange(0,100);
    progressBar->setValue(0);
    edit->setGeometry(0,0,20,5);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::disableTools(bool disable){
    tPanel->disableToolPanel(disable);
    ui->actionBox->setDisabled(disable);
    ui->actionSave->setDisabled(disable);
    ui->actionSave_As->setDisabled(disable);
    ui->actionClose->setDisabled(disable);
}
/////////////////////////////////////////////////////////////////////
void MainWindow::openGameObjectSlot(){
    QString fileName;
    fileName="D:/Projects/DUMPViewer/DUMPViewer/aaa.sgo";//QFileDialog::getOpenFileName(this,tr("Open game object"),app->currentPath(),tr("Game object files(*.sgo)"));
    if(!fileName.isEmpty()){
        if(core->loadCurrentGameObject(fileName)){
            tPanel->resetToolPanel();
            view->addModel(core->currentObject()->getMainMesh());
            for(unsigned int n=0;n!=core->currentObject()->LODsSize();n++){
                view->addModel(core->currentObject()->getLod(n));
            }
            setWindowTitle(QString::fromStdString(core->currentObject()->getName()));
            disableTools(false);
            modelFileName=fileName;
            emit updateTPanel();
        }
    }
}
/////////////////////////////////////////////////////////////////////
bool MainWindow::saveGameObjectSlot(){
    if(modelFileName.isEmpty()){
        QString fileName;
        fileName=QFileDialog::getSaveFileName(this,tr("Save game object"),core->currentPath(),tr("Game object files(*.sgo)"));
        if(fileName.isEmpty()){
            return false;
        }
        modelFileName=fileName;
    }
    saveModelFile();
    return true;
}
/////////////////////////////////////////////////////////////////////
void MainWindow::saveGameObjectAsSlot(){
    QString fileName;
    fileName=QFileDialog::getSaveFileName(this,tr("Save game object"),core->currentPath(),tr("Game object files(*.sgo)"));
    if(fileName.isEmpty()){
        return;
    }
    modelFileName=fileName;
    saveModelFile();
}
/////////////////////////////////////////////////////////////////////
void MainWindow::newGameObjectSlot(){
    newGameObjectNameWindow nameDialog(this);
    nameDialog.setDefaultName(core->defaultObjectName());
    if(nameDialog.exec()==QDialog::Accepted){
        QString name=nameDialog.getName();
        core->deleteCurrentObject();
        core->setCurrentObject(new editabelGameObject(name));
        setWindowTitle(name);
        disableTools(false);
    }
}
/////////////////////////////////////////////////////////////////////
void MainWindow::showBoundBoxSlot(){

}
/////////////////////////////////////////////////////////////////////
void MainWindow::closeCurrentObjectSlot(){
    if(!core->currentObject()->isSaved()){
        QMessageBox box(this);
        box.setWindowTitle(tr("Save?"));
        box.setIcon(QMessageBox::Question);
        box.setText(tr("Save object \n")+QString::fromStdString(core->currentObject()->getName()));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        switch(box.exec()){
            case(QMessageBox::Yes):{
                if(!saveGameObjectSlot()){//если юзер согласился на сохранение, а оно не произошло
                    return;//просто выходим
                }
                break;
            }
            case(QMessageBox::Cancel):{
                return;
            }
        }
    }
    disableTools(true);//сначала запретить, потом сбрасывать. Последовательность важна
    tPanel->resetToolPanel();
    modelFileName.clear();
    core->deleteCurrentObject();
}
///////////////////////////////////////////////////////////////////////////////////////
void MainWindow::loadShaders(){



}
///////////////////////////////////////////////////////////////////////////////////////
void MainWindow::someChanged(){
    view->update();
    tPanel->update();
}
/////////////////////////////////////////////////////////////////////////
bool MainWindow::saveModelFile(){
    return core->saveCurrentGameObject(modelFileName);
}
//////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setCorePointer(editorCore *pointer){
    this->core=pointer;

    core->setMainWindowPointer(this);
    core->setViewWindowPointer(view);

    progressBar=new QProgressBar;
    statusLable=new QLabel(tr("Status:"));
    tPanel=new toolWidget(this);
    tPanel->setCorePointer(pointer);
    disableTools(true);

    setWidgetsGeometry();
    connections();

    lastOpenDir=QApplication::applicationDirPath();
    createStatusBar();
    this->setWindowTitle(core->programmName());



}
