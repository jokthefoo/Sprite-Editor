#ifndef MODEL_H
#define MODEL_H
#include <QMouseEvent>
#include <vector>
#include <project.h>
#include <grid.h>
#include <tool.h>
#include <QTimer>

class Model // the model updates the view by sending signals
{

private:
    Project * project;
    Tool * currentTool;
    QColor currentColor;
    int brushSize;
    std::vector<Tool*> tools;
    QTimer timer;


public:
    Model();
    Model(const Model&);
    Model & operator=(const Model&);
    void swap(Model&);
    ~Model();
    Project * getProject();
    void rotateImage(int);
    void changeTool(int);
    Tool * getCurrentTool();
    void setColor(QColor);
    QColor getColor();
    void setBrushSize(int);
    int getBrushSize();

};

#endif // MODEL_H
