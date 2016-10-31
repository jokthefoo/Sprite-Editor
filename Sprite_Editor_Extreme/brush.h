#ifndef BRUSH_H
#define BRUSH_H
#include <grid.h>
#include <QPoint>
#include <tool.h>


class Brush : public Tool
{
public:
    Brush();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*) override;
    QPointF lastPoint;
    bool drawing = false;
    void virtual setColor(QColor color) override;
};

#endif // BRUSH_H
