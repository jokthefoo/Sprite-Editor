#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPaintEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QImage>
#include <grid.h>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateEditor(QImage * image);
    ~MainWindow();

signals:
    void sendMouseInput(QMouseEvent *);
    void sendButtonInput(QString buttonName);

public slots:
    void getButton();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *);
private:
    int default_width = 256;
    int default_height = 256;

    Ui::MainWindow * ui;
    Grid * grid;
    QGraphicsRectItem * boundary;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
