#include "controller.h"
#include <vector>;

Controller::Controller(MainWindow * w)
{
   this->view = w;
   QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
   QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);
   QObject::connect(w, &MainWindow::sendColorChange, this, &Controller::receiveColorChange);
   QObject::connect(w, &MainWindow::sendPropertyChange, this, &Controller::receivePropertyChange);
   QObject::connect(this, &Controller::sendImage, w, &MainWindow::updateScreen);
   QObject::connect(this, &Controller::sendColor, w, &MainWindow::updateColor);
   emit sendImage(model.getProject()->getCurrentFrame()->getImage());

}

Controller::~Controller(){

}

void Controller::receivePropertyChange(QString s, std::vector<int> v){
    if(v.size()>0){
        if(QString::compare(s, QString::fromStdString("brushSize"))==0){
            if(v.front()>0){
                model.getProject()->getCurrentFrame()->setDrawScale(v.front()); // there may be a better way to do this
            }
        }
    }
}

void Controller::receiveMouseInput(QPointF point)
{
    model.drawPixel(point.x(),point.y());
    emit sendImage(model.getProject()->getCurrentFrame()->getImage());
}

void Controller::receiveButtonInput(QToolButton *)
{
   // decode buttons here
   // std::cout << button->objectName().toStdString() << std::endl;
}

void Controller::receiveColorChange(QLabel * button){ // used for the color picker
    QString str = button->objectName();
    int x =  QString::compare(str, QString::fromStdString("leftColor"), Qt::CaseInsensitive);
    if(x == 0){
        QColor c = QColorDialog::getColor(Qt::white);
        model.setColor(c);
        emit sendColor(c);
    }
}

