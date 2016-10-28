#include "controller.h"

Controller::Controller(MainWindow * w)
{
   this->view = w;
   QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
   QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);
   QObject::connect(w, &MainWindow::sendLabelInput, this, &Controller::receiveLabelInput);
   QObject::connect(this, &Controller::sendImage, w, &MainWindow::updateScreen);
   QObject::connect(this, &Controller::changeSelectedColor, w, &MainWindow::ColorChange);
   emit sendImage(model.getProject()->getCurrentFrame()->getImage());

}

Controller::~Controller(){

}




void Controller::receiveMouseInput(QPointF point)
{
    model.drawPixel(point.x(),point.y());
    emit sendImage(model.getProject()->getCurrentFrame()->getImage());
}

void Controller::receiveButtonInput(QToolButton * button)
{
   // decode buttons here
   // std::cout << button->objectName().toStdString() << std::endl;
}

void Controller::receiveLabelInput(QLabel * button){ // used for the color picker
    QString str = button->objectName();
    int x =  QString::compare(str, QString::fromStdString("leftColor"), Qt::CaseInsensitive);
    if(x == 0){
        QColor c = QColorDialog::getColor(Qt::white);
        model.setColor(c);
        emit changeSelectedColor(c);
    }
}

