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
    ~PolygonBrush();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
    bool drawing;
private:
    std::vector<QPointF> points;
    std::vector<QColor> colors;
};

#endif // POLYGONBRUSH_H
