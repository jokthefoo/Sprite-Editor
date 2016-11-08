#ifndef FILLBUCKET_H
#define FILLBUCKET_H
#include <tool.h>
#include <QImage>

class FillBucket : public Tool
{
public:
    FillBucket();
    ~FillBucket();
    void virtual applyTool(Grid*, QPointF, QMouseEvent*, QColor, int, Project*) override;
private:
    QPointF lastPoint;
    void floodFill(QImage*, int, int, QColor, QColor);
};

#endif // FILLBUCKET_H
