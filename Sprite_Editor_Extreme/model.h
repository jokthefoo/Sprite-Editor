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
    Project project;

public:
    Model();
    ~Model();
    void changeTool(QString toolName);
    void applyTool(Grid grid, Tool tool, QPoint pos);

};

#endif // MODEL_H
