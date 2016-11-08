#ifndef TOOL_H
#define TOOL_H
#include <grid.h>
#include <QPointF>
#include <QColor>
#include <QMouseEvent>
#include <project.h>

class Tool
{
public:
    Tool();
    void virtual applyTool(Grid *, QPointF, QMouseEvent*,QColor, int, Project*);
   ~Tool();
    std::atomic_bool drawing;
private:

};

#endif // TOOL_H
