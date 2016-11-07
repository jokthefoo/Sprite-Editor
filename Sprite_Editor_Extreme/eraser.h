#ifndef ERASER_H
#define ERASER_H

#include <grid.h>
#include <QPoint>
#include <tool.h>


class Eraser : public Tool
{
public:
    Eraser();
     ~Eraser();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
    QPointF lastPoint;
    bool drawing = false;
};

#endif // ERASER_H
