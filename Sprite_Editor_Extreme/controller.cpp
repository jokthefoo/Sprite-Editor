#include "controller.h"


Controller::Controller()
{





}

Controller::~Controller(){

}

void Controller::receiveMouseInput(QMouseEvent * event){

}

void Controller::receiveButtonInput(){
    QObject *sender = QObject::sender();
    QString buttonName = sender->objectName();
}
