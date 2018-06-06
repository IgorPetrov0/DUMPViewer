#include "lodsbox.h"
#include "ui_lodsbox.h"

lodsBox::lodsBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lodsBox)
{
    ui->setupUi(this);

}
//////////////////////////////////////////////////
lodsBox::~lodsBox()
{
    delete ui;
}
//////////////////////////////////////////////////
