#include "configurationform.h"
#include "ui_configurationform.h"

ConfigurationForm::ConfigurationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationForm)
{
    ui->setupUi(this);
}

ConfigurationForm::~ConfigurationForm()
{
    delete ui;
}

Ui::ConfigurationForm * ConfigurationForm::get(){
    return this->ui;
}
