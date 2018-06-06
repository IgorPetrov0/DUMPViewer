#include "newgameobjectnamewindow.h"
#include "ui_newgameobjectnamewindow.h"

newGameObjectNameWindow::newGameObjectNameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newGameObjectNameWindow)
{
    ui->setupUi(this);
    connect(ui->OKButton,SIGNAL(clicked(bool)),this,SLOT(okClicked(bool)));
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(canselClicked(bool)));
    setWindowTitle(tr("New game object name"));
    ui->nameLine->setLocale(QLocale::English);
}
////////////////////////////////////////////////////////////////////////////////
newGameObjectNameWindow::~newGameObjectNameWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////
void newGameObjectNameWindow::okClicked(bool state){
    if(ui->nameLine->text().isEmpty()){
        reject();
    }
    else{
        accept();
    }
}
////////////////////////////////////////////////////////////////////////////////
void newGameObjectNameWindow::canselClicked(bool state){
    reject();
}
////////////////////////////////////////////////////////////////////////////////
QString newGameObjectNameWindow::getName(){
    return ui->nameLine->text();
}
////////////////////////////////////////////////////////////////////////////////
void newGameObjectNameWindow::setDefaultName(QString name){
    ui->nameLine->setText(name);
    ui->nameLine->setSelection(0,name.size());
}
////////////////////////////////////////////////////////////////////////////////

