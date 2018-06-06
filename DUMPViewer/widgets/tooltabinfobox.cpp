#include "tooltabinfobox.h"
#include "ui_tooltabinfobox.h"

toolTabInfoBox::toolTabInfoBox(QWidget *parent) :
    dumpViewerWidget(parent),
    ui(new Ui::toolTabInfoBox)
{
    ui->setupUi(this);

    connect(ui->loadButton,SIGNAL(clicked(bool)),this,SLOT(loadSlot()));
    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SIGNAL(deleteSignal()));
    ui->infoBox->setOriginSize();

}
/////////////////////////////////////////////////////////////////////////////
toolTabInfoBox::~toolTabInfoBox(){
    delete ui;
}
////////////////////////////////////////////////////////
void toolTabInfoBox::loadSlot(){
    emit loadSignal();
}
////////////////////////////////////////////////////////
void toolTabInfoBox::resizeEvent(QResizeEvent *event){
    QRect rect;
    rect=ui->meshGroup->geometry();
    rect.setWidth(this->width()-15);
    ui->meshGroup->setGeometry(rect);

    rect=ui->fileNameLine->geometry();
    rect.setWidth(ui->meshGroup->width()-20);
    ui->fileNameLine->setGeometry(rect);

    rect=ui->loadButton->geometry();
    rect.setX(10);
    ui->loadButton->setGeometry(rect);

    rect=ui->deleteButton->geometry();
    rect.setX(ui->meshGroup->width()-10-rect.width());
    ui->deleteButton->setGeometry(rect);

    rect=ui->infoBox->geometry();
    rect.setX(ui->loadButton->geometry().x());
    rect.setWidth(ui->meshGroup->geometry().width()-20);
    ui->infoBox->setGeometry(rect);
}
/////////////////////////////////////////////////////////////////
void toolTabInfoBox::setFileName(QString fileName){
    ui->fileNameLine->setText(fileName);
}
///////////////////////////////////////////////////////////////////
void toolTabInfoBox::clear(){
    ui->fileNameLine->clear();
    ui->infoBox->clear();
}
///////////////////////////////////////////////////////////////////
void toolTabInfoBox::calculateMeshParameters(meshObject *mesh){
    ui->infoBox->calculateMeshParameters(mesh);
}

