#ifndef MODEL_H
#define MODEL_H
#include <QMouseEvent>
#include <vector>
#include <project.h>
#include <grid.h>
#include <tool.h>

class Model // the model updates the view by sending signals
{

private:
    Project * project;
    QColor currentColor;
    Tool * currentTool;
    std::vector<Tool*> tools;



public:
    Model();
    ~Model();

    void drawPixel(int x, int y);
    void setColor(QColor);
    Project * getProject();
    QColor getColor();
    void drawLine(QPointF , QPointF );
    void rotateImage(int);
    void changeTool(int);
    Tool * getCurrentTool();

};

#endif // MODEL_H
