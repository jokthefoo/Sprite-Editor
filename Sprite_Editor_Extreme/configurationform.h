#ifndef CONFIGURATIONFORM_H
#define CONFIGURATIONFORM_H

#include <QDialog>

namespace Ui {
class ConfigurationForm;
}

class ConfigurationForm : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationForm(QWidget *parent = 0);
    ~ConfigurationForm();
    Ui::ConfigurationForm * get();


private:
    Ui::ConfigurationForm *ui;
};

#endif // CONFIGURATIONFORM_H
