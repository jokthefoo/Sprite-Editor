#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPaintEvent>
#include <grid.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);
private:
    Ui::MainWindow *ui;
    Grid * grid;

};

#endif // MAINWINDOW_H
