#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPaintEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QImage>
#include <QToolButton>
#include <grid.h>
#include <iostream>
#include <QLabel>
#include <QPalette>


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
    void sendButtonInput(QToolButton*);
    void sendLabelInput(QLabel*);

public slots:
    void getButton();
    void getLabel();
    void updateScreen(QImage * toShow);
    void ColorChange(QColor); // left is false right is true
    // void updatePreview(std::vector<Grid>);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    //void mousePressEvent(QMouseEvent *);
private:
    void connectComponents();
    QGraphicsRectItem * boundary; // should move this to the model
    Ui::MainWindow * ui;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
