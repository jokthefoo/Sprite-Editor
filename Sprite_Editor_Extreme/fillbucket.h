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
    void virtual applyTool(Grid*, QPointF, QMouseEvent*) override;
    QPointF lastPoint;
    bool drawing;
    void virtual setColor(QColor color) override;
private:
    void floodFill(QImage*, int, int, QColor, QColor);
};

#endif // FILLBUCKET_H
