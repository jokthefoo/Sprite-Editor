#ifndef FILLBUCKET_H
#define FILLBUCKET_H

#include <tool.h>
#include <grid.h>
#include <QPoint>
#include <QColor>
#include <QImage>

class FillBucket : public Tool
{
public:
    FillBucket();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int) override;
    QPointF lastPoint;
    bool drawing;
private:
    void floodFill(QImage*, int, int, QColor, QColor);
};

#endif // FILLBUCKET_H
