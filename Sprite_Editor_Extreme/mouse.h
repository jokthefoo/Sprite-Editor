#ifndef MOUSE_H
#define MOUSE_H
#include <grid.h>
#include <QPoint>
#include <tool.h>


class Mouse : public Tool
{
public:
    Mouse();
    ~Mouse();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
    QPointF lastPoint;
    bool drawing = false;
};

#endif // MOUSE_H
