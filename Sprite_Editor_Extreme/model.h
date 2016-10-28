#ifndef MODEL_H
#define MODEL_H
#include <QMouseEvent>
#include <vector>
#include <project.h>
#include <grid.h>
#include <tool.h>

class model // the model updates the view by sending signals
{

private:
    std::vector<Tool> tools;
    Project project;

public:
    model();
    ~model();
    void changeTool(QString toolName);
    void applyTool(Grid grid, Tool tool, QPoint pos);

};

#endif // MODEL_H
