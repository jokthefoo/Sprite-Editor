#include "controller.h"

Controller::Controller(MainWindow * w)
{
   this->view = w;
   QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
   QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);
   QObject::connect(w, &MainWindow::sendPropertyChange, this, &Controller::receivePropertyChange);
   QObject::connect(this, &Controller::sendImage, w, &MainWindow::updateScreen);
   QObject::connect(this, &Controller::sendColor, w, &MainWindow::updateColor);
   emit sendImage(model.getProject()->getCurrentFrame()->getImage());
   drawing = false;

}

Controller::~Controller(){

}

void Controller::receivePropertyChange(Property p){
    if(p.values.size()>0){
        if(p.name.toStdString().compare("brushSize")==0){
            if(p.values.front()>0){
                model.getProject()->getCurrentFrame()->setDrawScale(p.values.front());
            }
        }
        if(p.name.toStdString().compare("canvasSize")==0){
            model.getProject()->setCanvasSize(p.values[0],p.values[1]);
            emit sendImage(model.getProject()->getCurrentFrame()->getImage());
        }
    }
}

void Controller::receiveMouseInput(QPointF point, QMouseEvent *event)
{
    Grid * currentFrame = model.getProject()->getCurrentFrame();
    if(model.getCurrentTool()!=nullptr){
        Tool * tool = model.getCurrentTool();
        tool->applyTool(currentFrame,point, model.getColor(), event);
        emit sendImage(model.getProject()->getCurrentFrame()->getImage());
    }
}

// decode buttons here
void Controller::receiveButtonInput(QWidget * child)
{

    QLabel * label = dynamic_cast<QLabel*>(child); // type check the input
    if(label!=NULL){
        QString str = label->objectName();
        int x =  QString::compare(str, "leftColor", Qt::CaseInsensitive);
        if(x == 0){
            QColor c = QColorDialog::getColor(Qt::white);
            model.setColor(c);
            emit sendColor(c);
        }
        return;
    }

    QToolButton * button = dynamic_cast<QToolButton*>(child);
    if(button!=NULL){
        std::string name = button->objectName().toStdString();
        QImage * image = model.getProject()->getCurrentFrame()->getImage();
        if(name == "rotate_Right_Button")
        {
            model.rotateImage(90);
            emit sendImage(image);
        }else if(name  == "rotate_Left_Button")
        {
            model.rotateImage(-90);
            emit sendImage(image);
        } else if(name == "brush_Button"){
            model.changeTool(0);
        }else{
            //......todo
        }

        return;
    }
}


