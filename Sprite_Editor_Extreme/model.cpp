#include "model.h"

Model::Model()
{
    project = new Project();
    setColor(Qt::white);
}

Model::~Model(){
    delete project;
}

void Model::setColor(QColor q){
    currentColor=q;
}

QColor Model::getColor(){
    return currentColor;
}

void Model::drawPixel(int x, int y){ // this will be repurposed elsewhere
    //todo
    if(project->getCurrentFrame()->containsCoordinate(x,y)){
         project->getCurrentFrame()->setPixelColor(x,y,currentColor);
    }
}

Project* Model::getProject(){
    return project;
}

void Model::changeTool(QString toolName){

}

void Model::applyTool(Tool tool, QPoint pos){


}


