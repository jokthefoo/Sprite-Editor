#include "eraser.h"

Eraser::Eraser()
{

}

void Eraser::applyTool(Grid* frame, QPointF mousePosition, QMouseEvent* event, QColor color, int brushSize)
{
    // Restricts the action to only when in the drawing area.
    if (frame->containsCoordinate(mousePosition.x(), mousePosition.y()))
    {
        // Don't update image every time mouse event is fired
        if (event->type() == QEvent::MouseButtonPress && !drawing)
        {
            drawing = true;
            frame->setPixelColor(mousePosition.x(), mousePosition.y(), Qt::white, brushSize);
            lastPoint = mousePosition;
        } else if (drawing && event->type() == QEvent::MouseMove)
        {
            frame->drawLinePixels(lastPoint, mousePosition, Qt::white, brushSize);
            lastPoint = mousePosition;
        } else if (drawing && event->type() == QEvent::MouseButtonRelease)
        {
            drawing = false;
        }
    }
}
