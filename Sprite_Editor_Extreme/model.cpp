#include "model.h"
#include <brush.h>
#include <eraser.h>
#include <fillbucket.h>
#include <polygonbrush.h>
#include <selectionTool.h>

Model::Model()
{
    project = new Project();
    Tool * brush = new Brush();
    Tool * eraser = new Eraser();
    Tool * fillBucket = new FillBucket();
    Tool * polygonBrush = new PolygonBrush();
    Tool * selectionTool = new SelectionTool();
    currentColor = Qt::black;
    brushSize = 1;
    tools.push_back(brush);
    tools.push_back(eraser);
    tools.push_back(fillBucket);
    tools.push_back(polygonBrush);
    tools.push_back(selectionTool);
    currentTool = brush; // need to decide on the default tool
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
    for(auto it = tools.begin(); it < tools.end(); it++){
        delete *it;
    }
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
    } else if (i == 3)
    {
        currentTool = tools[3];
    }else if (i == 4)
    {
        currentTool = tools[4];
    }
}

void Model::setBrushSize(int size)
{
    brushSize = size;
}

int Model::getBrushSize()
{
    return brushSize;
}

QColor Model::getColor()
{
    return currentColor;
}

void Model::setColor(QColor c)
{
    currentColor = c;
}

Tool * Model::getCurrentTool(){
    return currentTool;
}



