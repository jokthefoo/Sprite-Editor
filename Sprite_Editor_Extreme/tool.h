#ifndef TOOL_H
#define TOOL_H
#include <grid.h>
#include <QPointF>
#include <QColor>
#include <QMouseEvent>

class Tool
{
public:
    Tool();
    void virtual applyTool(Grid *, QPointF, QMouseEvent*,QColor, int);

private:

};

#endif // TOOL_H
