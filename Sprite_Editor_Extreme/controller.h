#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QMouseEvent>
#include <model.h>
#include <mainwindow.h>

// following the mvc design pattern : https://en.wikipedia.org/wiki/Model-view-controller
class Controller : public QObject
{
    Q_OBJECT

private:
    MainWindow * view;
    Model model;

public:
    Controller();
    Controller(MainWindow*);
    ~Controller();
    //should have slots to capture the input from the user and then will use the model to change
    //the current states.

signals:
    void sendImage(QImage *);

public slots:

    void receiveButtonInput(QString);
    void receiveMouseInput(QPointF);

};

#endif // CONTROLLER_H
