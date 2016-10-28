
#include "controller.h"
#include <mainwindow.h>


Controller::Controller(MainWindow * w)
{
   this->view = w;
   QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
   QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);
   QObject::connect(this, &Controller::sendImage, w, &MainWindow::updateScreen);

}

Controller::~Controller(){

}

void Controller::receiveMouseInput(QPointF point)
{
    this->model.getCurrentFrame()->setPixelColor(point.x(),point.y(),Qt::white);
    emit sendImage(this->model.getCurrentFrameImage());
}

void Controller::receiveButtonInput()
{
    QObject *sender = QObject::sender();
    QString buttonName = sender->objectName();
    std::cout << "rawr" << std::endl;
}

