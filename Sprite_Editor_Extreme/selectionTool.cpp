#include "selectionTool.h"

SelectionTool::SelectionTool()
{
    drawing = false;
}

SelectionTool::~SelectionTool(){

}

void SelectionTool::applyTool(Grid * frame, QPointF mousePosition, QMouseEvent * event, QColor color, int brushSize, Project* p)
{
    // Restricts action to drawing area
    if (frame->containsCoordinate(mousePosition.x(), mousePosition.y()))
    {
        if (event->type() == QEvent::MouseButtonPress && !drawing)
        {
            drawing = true;
            p->addEdit();
            origin = mousePosition.toPoint();
        }
        else if(event->type() == QEvent::MouseButtonRelease && drawing)
        {
            drawing = false;
            QPoint topLeft, botRight;
            if(origin.x() < mousePosition.x())
            {
                topLeft.setX(origin.x());
                botRight.setX(mousePosition.x());
            }
            else
            {
                topLeft.setX(mousePosition.x());
                botRight.setX(origin.x());
            }

            if(origin.y() > mousePosition.y())
            {
                topLeft.setY(mousePosition.y());
                botRight.setY(origin.y());
            }
            else
            {
                topLeft.setY(origin.y());
                botRight.setY(mousePosition.y());
            }

            QImage selection(frame->getImage()->copy(QRect(topLeft,botRight)));
            QClipboard *clip = QApplication::clipboard();
            clip->setImage(selection);

        }
    }
}
