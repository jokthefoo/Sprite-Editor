
#include "fillbucket.h"

FillBucket::FillBucket()
{
    this->drawing = false;
}

void FillBucket::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event)
{
    // Restricts action to drawing area
    if (frame->containsCoordinate(mousePosition.x(), mousePosition.y()))
    {
        if (drawing)
        {
            return;
        }

        if (event->type() == QEvent::MouseButtonPress && !drawing)
        {
            drawing = true;
            QColor targetColor = frame->pixelColor(mousePosition.x(), mousePosition.y());
            floodFill(frame->getImage(), mousePosition.x(), mousePosition.y(), targetColor, color);
            drawing = false;
        }
    }
}

// Source: Flood fill - Wikipedia
void FillBucket::floodFill(QImage * image, int x, int y, QColor targetColor, QColor replacementColor)
{

    if (((x >= image->width() || x < 0)||(y >= image->height() || y < 0)))
    {
        return;
    }else{
        if (targetColor == replacementColor)
        {
            return;
        }

        if (image->pixelColor(x, y) != targetColor)
        {
            return;
        }

        image->setPixelColor(x, y, replacementColor);


        floodFill(image, x, y + 1, targetColor, replacementColor);
        floodFill(image, x, y - 1, targetColor, replacementColor);
        floodFill(image, x - 1, y, targetColor, replacementColor);
        floodFill(image, x + 1, y, targetColor, replacementColor);
    }

    return;
}

void FillBucket::setColor(QColor color)
{
    this->color = color;
}
