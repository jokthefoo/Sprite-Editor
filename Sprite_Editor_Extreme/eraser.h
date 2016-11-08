#ifndef ERASER_H
#define ERASER_H
#include <tool.h>


class Eraser : public Tool{
public:
    Eraser();
     ~Eraser();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
private:
    QPointF lastPoint;

};

#endif // ERASER_H
