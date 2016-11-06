#include "brush.h"

Brush::Brush()
{

}

void Brush::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event, QColor color, int brushSize, Project* p ){
    if(frame->containsCoordinate(mousePosition.x(),mousePosition.y())){ // restricts the action to only when in the drawing area.
        if(event->type() == QEvent::MouseButtonPress && !drawing) // other wise we would be updating the image every time a mouse event was fired
        {
            drawing = true;
            frame->setPixelColor(mousePosition.x(),mousePosition.y(),color,brushSize);
            lastPoint = mousePosition;
        }else if(drawing && event->type() == QEvent::MouseMove)
        {
            frame->drawLinePixels(lastPoint,mousePosition,color,brushSize);
            lastPoint = mousePosition;
        }else if(drawing && event->type() == QEvent::MouseButtonRelease)
        {
            p->addEdit();
            drawing = false;
        }
  }
}


