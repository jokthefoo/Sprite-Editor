#ifndef CREATENEW_H
#define CREATENEW_H

#include <QDialog>

namespace Ui {
class createNew;
}

class createNew : public QDialog
{
    Q_OBJECT

public:
    explicit createNew(QWidget *parent = 0);
    ~createNew();

private slots:

private:
    Ui::createNew *ui;
};

#endif // CREATENEW_H
