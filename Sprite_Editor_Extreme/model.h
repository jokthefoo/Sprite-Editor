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
    Tool * currentTool;
    std::vector<Tool*> tools;



public:
    Model();
    ~Model();
    Project * getProject();
    void rotateImage(int);
    void changeTool(int);
    Tool * getCurrentTool();

};

#endif // MODEL_H
