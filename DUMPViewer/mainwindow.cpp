#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    app=new application;
    app->setMainWindowPointer(this);
    ui->setupUi(this);//такая последовательность важна

    view=new viewWindow(this);
    app->setViewWindowPointer(view);

    progressBar=new QProgressBar;
    statusLable=new QLabel(tr("Status:"));
    tPanel=new toolWidget(app,this);
    disableTools(true);

    setWidgetsGeometry();
    connections();

    lastOpenDir=QApplication::applicationDirPath();
    createStatusBar();
    this->setWindowTitle(app->programmName());
}
//////////////////////////////////////////////////////
MainWindow::~MainWindow()
{  
    delete ui;
    delete progressBar;
    delete statusLable;
    delete tPanel;
    app->deleteCurrentObject();
    delete view;
    delete app;
}
////////////////////////////////////////////////////////
void MainWindow::connections(){
    connect(ui->actionNew,SIGNAL(triggered(bool)),this,SLOT(newGameObjectSlot()));
    connect(ui->actionClose,SIGNAL(triggered(bool)),this,SLOT(closeCurrentObjectSlot()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(saveGameObjectSlot()));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openGameObjectSlot()));
    connect(this,SIGNAL(objectLoaded()),tPanel,SLOT(updateInfoSlot()));
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
        if(app->loadCurrentObject(fileName)){
            tPanel->resetToolPanel();
            view->addModel(app->currentObject()->getMainMesh());
            for(unsigned int n=0;n!=app->currentObject()->LODsSize();n++){
                view->addModel(app->currentObject()->getLod(n));
            }
            view->update();
            setWindowTitle(QString::fromStdString(app->currentObject()->getName()));
            disableTools(false);
            emit objectLoaded();//сигналим подчиненным виджетам обновиться
            modelFileName=fileName;
        }
    }
}
/////////////////////////////////////////////////////////////////////
bool MainWindow::saveGameObjectSlot(){
    if(modelFileName.isEmpty()){
        QString fileName;
        fileName=QFileDialog::getSaveFileName(this,tr("Save game object"),app->currentPath(),tr("Game object files(*.sgo)"));
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
    fileName=QFileDialog::getSaveFileName(this,tr("Save game object"),app->currentPath(),tr("Game object files(*.sgo)"));
    if(fileName.isEmpty()){
        return;
    }
    modelFileName=fileName;
    saveModelFile();
}
/////////////////////////////////////////////////////////////////////
void MainWindow::newGameObjectSlot(){
    newGameObjectNameWindow nameDialog(this);
    nameDialog.setDefaultName(app->defaultObjectName());
    if(nameDialog.exec()==QDialog::Accepted){
        QString name=nameDialog.getName();
        app->deleteCurrentObject();
        app->setCurrentObject(new editabelGameObject(name));
        setWindowTitle(name);
        disableTools(false);
    }
}
/////////////////////////////////////////////////////////////////////
void MainWindow::showBoundBoxSlot(){

}
/////////////////////////////////////////////////////////////////////
void MainWindow::closeCurrentObjectSlot(){
    if(!app->currentObject()->isSaved()){
        QMessageBox box;
        box.setWindowTitle(tr("Save?"));
        box.setIcon(QMessageBox::Question);
        box.setText(tr("Save object \n")+QString::fromStdString(app->currentObject()->getName()));
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
    app->deleteCurrentObject();
}
/////////////////////////////////////////////////////////////////////////
bool MainWindow::saveModelFile(){
    return app->saveCurrentObject(modelFileName);
}
//////////////////////////////////////////////////////////////////////////////////////
