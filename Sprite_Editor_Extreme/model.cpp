#include "model.h"
#include <brush.h>
#include <eraser.h>

Model::Model()
{
    project = new Project();
    Tool * brush = new Brush();
    Tool * eraser = new Eraser();
    eraser->color = Qt::white;
    brush->color = Qt::black;
    tools.push_back(brush);
    tools.push_back(eraser);
    currentTool = brush; // need to decide on the default tool
}

Model::~Model(){
    delete project;
}


Project* Model::getProject(){
    return project;
}

void Model::rotateImage(int degrees){
    project->getCurrentFrame()->rotateImage(degrees);
}

void Model::changeTool(int i){
    if(i==0){
        currentTool=tools[0];
    } else if (i == 1)
    {
        currentTool = tools[1];
    }
}

Tool * Model::getCurrentTool(){
    return currentTool;
}



