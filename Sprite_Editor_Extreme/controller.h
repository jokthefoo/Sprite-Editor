#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QMouseEvent>
#include <QToolButton>
#include <QLabel>
#include <QColorDialog>
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
    void sendColor(QColor);

public slots:
    void receiveColorChange(QLabel*);
    void receiveButtonInput(QToolButton*);
    void receiveMouseInput(QPointF);
    void receivePropertyChange(QString, std::vector<int>);

};

#endif // CONTROLLER_H
