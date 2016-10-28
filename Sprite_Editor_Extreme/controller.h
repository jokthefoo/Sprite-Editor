#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QMouseEvent>

// following the mvc design pattern : https://en.wikipedia.org/wiki/Model-view-controller
class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();
    //should have slots to capture the input from the user and then will use the model to change
    //the current states.

public slots:
    void receiveButtonInput();
    void receiveMouseInput(QMouseEvent *);

};

#endif // CONTROLLER_H
