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
   drawing = false;

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

void Controller::receiveMouseInput(QPointF point, QEvent *event)
{
    //Also use to check what tool is selected
    if(event->type() == QEvent::MouseButtonPress && !drawing)
    {
        drawing = true;
        model.drawPixel(point.x(),point.y());
        lastPoint = point;
    }else if(drawing && event->type() == QEvent::MouseMove)
    {
        model.drawLine(lastPoint,point);
        lastPoint = point;
    }else if(drawing && event->type() == QEvent::MouseButtonRelease)
    {
        drawing = false;\
    }
    emit sendImage(model.getProject()->getCurrentFrame()->getImage());
}

void Controller::receiveButtonInput(QToolButton *button)
{
   // decode buttons here
    //std::cout << button->objectName().toStdString() << std::endl;
    if(button->objectName().toStdString() == "rotate_Right_Button")
    {
        model.rotateImage(90);
    }
    if(button->objectName().toStdString() == "rotate_Left_Button")
    {
        model.rotateImage(-90);
    }
    emit sendImage(model.getProject()->getCurrentFrame()->getImage());
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

