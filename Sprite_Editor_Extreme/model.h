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
    int brushSize;

    Project * project;
    Tool * currentTool;
    QColor currentColor;
    std::vector<Tool*> tools;

public:
    Model();
    Model(const Model&);
    Model & operator=(const Model&);
    void swap(Model&);
    ~Model();

    QColor getColor();
    int getBrushSize();
    void setBrushSize(int);
    void setColor(QColor);
    void rotateImage(int);
    void changeTool(int);
    Project * getProject();
    Tool * getCurrentTool();

};

#endif // MODEL_H
