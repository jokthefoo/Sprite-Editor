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
    std::vector<Tool> tools;
    Project * project;
    QColor currentColor;

public:
    Model();
    ~Model();
    void changeTool(QString toolName);
    void applyTool(Tool tool, QPoint pos);
    void drawPixel(int x, int y);
    void setColor(QColor);
    Project * getProject();
    QColor getColor();

};

#endif // MODEL_H
