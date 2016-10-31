#ifndef ERASER_H
#define ERASER_H

#include <grid.h>
#include <QPoint>
#include <tool.h>


class Eraser : public Tool
{
public:
    Eraser();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*) override;
    QPointF lastPoint;
    bool drawing = false;
    void virtual setColor(QColor color) override;
};

#endif // ERASER_H
