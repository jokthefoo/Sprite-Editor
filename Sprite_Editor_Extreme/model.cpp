#include "model.h"
#include <brush.h>

Model::Model()
{
    project = new Project();
    Tool * brush = new Brush();
    brush->color = Qt::black;
    tools.push_back(brush);
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
    }
}

Tool * Model::getCurrentTool(){
    return currentTool;
}



