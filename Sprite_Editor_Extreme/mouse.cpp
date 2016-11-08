#include "mouse.h"

Mouse::Mouse()
{

}

Mouse::~Mouse(){

}

void Mouse::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event, QColor color, int brushSize, Project* p ){
    if(frame->containsCoordinate(mousePosition.x(),mousePosition.y())){ // restricts the action to only when in the drawing area.
        if(event->type() == QEvent::MouseButtonPress && !drawing) // other wise we would be updating the image every time a mouse event was fired
        {
            //p->addEdit();
            drawing = true;
            //frame->setPixelColor(mousePosition.x(),mousePosition.y(),color,brushSize);
            lastPoint = mousePosition;
        }else if(drawing && event->type() == QEvent::MouseMove)
        {
            //frame->drawLinePixels(lastPoint,mousePosition,color,brushSize);
            lastPoint = mousePosition;
        }else if(drawing && event->type() == QEvent::MouseButtonRelease)
        {
            drawing = false;
        }
  }
}
