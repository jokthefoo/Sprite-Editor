#ifndef BRUSH_H
#define BRUSH_H
#include <grid.h>
#include <QPoint>
#include <tool.h>


class Brush : public Tool
{
public:
    Brush();
    ~Brush();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
    QPointF lastPoint;
    bool drawing = false;
};

#endif // BRUSH_H
