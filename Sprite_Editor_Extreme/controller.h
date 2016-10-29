#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QMouseEvent>
#include <QToolButton>
#include <QLabel>
#include <QColorDialog>
#include <vector>
#include <model.h>
#include <mainwindow.h>

// following the mvc design pattern : https://en.wikipedia.org/wiki/Model-view-controller
class Controller : public QObject
{
    Q_OBJECT

private:
    MainWindow * view;
    Model model;
    bool drawing;
    QPointF lastPoint;


public:
    Controller();
    Controller(MainWindow*);
    ~Controller();
    //should have slots to capture the input from the user and then will use the model to change
    //the current states.

signals:
    void sendImage(QImage *);
    void sendColor(QColor);

public slots:
    void receiveButtonInput(QWidget*);
    void receiveMouseInput(QPointF, QMouseEvent*);
    void receivePropertyChange(Property);

};

#endif // CONTROLLER_H
