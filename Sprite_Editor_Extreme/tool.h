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
    void virtual applyTool(Grid *, QPointF, QMouseEvent*);
    QColor color;
    void virtual setColor(QColor color);

private:

};

#endif // TOOL_H
