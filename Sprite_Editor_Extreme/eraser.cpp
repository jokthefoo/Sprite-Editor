#include "eraser.h"

Eraser::Eraser()
{

}

void Eraser::applyTool(Grid* frame, QPointF mousePosition, QMouseEvent* event, QColor, int brushSize, Project* p)
{
    // Restricts the action to only when in the drawing area.
    if (frame->containsCoordinate(mousePosition.x(), mousePosition.y()))
    {
        QColor c(0,0,0,0);
        // Don't update image every time mouse event is fired
        if (event->type() == QEvent::MouseButtonPress && !drawing)
        {
            p->addEdit();
            drawing = true;
            frame->setPixelColor(mousePosition.x(), mousePosition.y(), c, brushSize);
            lastPoint = mousePosition;
        } else if (drawing && event->type() == QEvent::MouseMove)
        {
            frame->drawLinePixels(lastPoint, mousePosition, c, brushSize);
            lastPoint = mousePosition;
        } else if (drawing && event->type() == QEvent::MouseButtonRelease)
        {
            drawing = false;
        }
    }
}
