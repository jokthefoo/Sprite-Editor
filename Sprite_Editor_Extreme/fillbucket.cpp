
#include "fillbucket.h"

FillBucket::FillBucket()
{
    this->drawing = false;
}

FillBucket::~FillBucket(){

}


void FillBucket::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event, QColor color,int,Project* p)
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
            p->addEdit();
            int w = frame->getImage()->width();
            int h = frame->getImage()->height();
            int x = mousePosition.x();
            int y = mousePosition.y();

            if(x<0||y<0||x>=w||y>=h) return;
            drawing = true;
            QColor targetColor = frame->pixelColor(mousePosition.x(), mousePosition.y());
            targetColor.setAlpha(0);
            floodFill(frame->getImage(), mousePosition.x(), mousePosition.y(), targetColor, color);
            drawing = false;
        }
    }
}

// Source: Flood fill - Wikipedia
void FillBucket::floodFill(QImage * image, int x, int y, QColor targetColor, QColor replacementColor)
{
    int w = image->width();
    int h = image->height();
    if (((x>=w||x < 0)||(y >=h||y < 0)))
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
