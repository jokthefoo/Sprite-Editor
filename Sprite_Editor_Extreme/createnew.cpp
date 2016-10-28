#include "createnew.h"
#include "ui_createnew.h"


createNew::createNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createNew)
{
    ui->setupUi(this);
}

createNew::~createNew()
{
    delete ui;
}
