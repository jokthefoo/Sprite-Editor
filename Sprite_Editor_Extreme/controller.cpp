
#include "controller.h"
#include <mainwindow.h>


Controller::Controller(MainWindow * w)
{
   this->view = w;
   QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
   QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);

}

Controller::~Controller(){

}

void Controller::receiveMouseInput(QMouseEvent * event){
  //std::cout << "mouse input received" << std::endl; this works
}

void Controller::receiveButtonInput(){
    QObject *sender = QObject::sender();
    QString buttonName = sender->objectName();
    std::cout << "rawr" << std::endl;
}

