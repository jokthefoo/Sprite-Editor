#include "model.h"
#include <brush.h>
#include <eraser.h>
#include <fillbucket.h>

Model::Model()
{
    project = new Project();
    Tool * brush = new Brush();
    Tool * eraser = new Eraser();
    Tool * fillBucket = new FillBucket();
    eraser->color = Qt::white;
    brush->color = Qt::black;
    fillBucket->color = Qt::black;
    tools.push_back(brush);
    tools.push_back(eraser);
    tools.push_back(fillBucket);
    currentTool = brush;
}

Model::Model(const Model& other)
{
    this->project = other.project;
    this->tools = std::move(other.tools);
    this->currentTool = other.currentTool;
}

Model& Model::operator=(const Model& other)
{
    Model temp(other);
    this->swap(temp);
    return *this;
}

void Model::swap(Model& other)
{
    std::swap(currentTool,other.currentTool);
    std::swap(tools,other.tools);
    std::swap(project,other.project);
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
    } else if (i == 2)
    {
        currentTool = tools[2];
    }
}

Tool * Model::getCurrentTool(){
    return currentTool;
}



