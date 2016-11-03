#include "polygonbrush.h"

PolygonBrush::PolygonBrush()
{
    drawing = false;
}

void PolygonBrush::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event, QColor color, int brushSize)
{
    // Restricts action to drawing area
    if (frame->containsCoordinate(mousePosition.x(), mousePosition.y()))
    {
        if (event->type() == QEvent::MouseButtonPress && !drawing)
        {
            if (event->button() == Qt::LeftButton)
            {
                drawing = true;
                frame->setPixelColor(mousePosition.x(), mousePosition.y(), color, brushSize);
                points.push_back(mousePosition);
                drawing = false;
            } else if (event->button() == Qt::RightButton && points.size() > 2)
            {
                drawing = true;
                QPointF pointsArr[points.size()];
                std::copy(points.begin(), points.end(), pointsArr);
                frame->drawPolygon(pointsArr, points.size(), color, brushSize);
                points.clear();
                drawing = false;
            }
        }
    }
}
