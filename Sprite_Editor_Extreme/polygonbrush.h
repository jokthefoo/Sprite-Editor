#ifndef POLYGONBRUSH_H
#define POLYGONBRUSH_H

#include <grid.h>
#include <QPoint>
#include <tool.h>
#include <vector>

class PolygonBrush : public Tool
{
public:
    PolygonBrush();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int) override;
    bool drawing;
private:
    std::vector<QPointF> points;
};

#endif // POLYGONBRUSH_H
