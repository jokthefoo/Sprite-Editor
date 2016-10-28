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
#include "createnew.h"

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
    void sendMouseInput(QPointF);
    void sendButtonInput(QString buttonName);

public slots:
    void getButton();
    void updateScreen(QImage * toShow);
    // void updatePreview(std::vector<Grid>);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    //void mousePressEvent(QMouseEvent *);
private slots:
    void on_newSprite_clicked();

private:
    void connectComponents();
    QGraphicsRectItem * boundary; // should move this to the model
    Ui::MainWindow * ui;
    createNew * newView;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
