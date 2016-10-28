#include "model.h"

Model::Model()
{

}

Model::~Model(){

}

void Model::setColor(QColor q){
    currentColor=q;
}

QColor Model::getColor(){
    return currentColor;
}

void Model::drawShapeToCurrent(int x, int y, QPolygon poly){
    //todo
}

void Model::drawToCurrent(int x, int y){
    //todo
    if(project.getCurrentFrame()->containsCoordinate(x,y)){
         project.getCurrentFrame()->setPixelColor(x,y,currentColor);
    }
}


Grid * Model::getCurrentFrame(){
    return this->project.getCurrentFrame();
}

QImage * Model::getCurrentFrameImage(){
    return this->project.getCurrentFrameImage();
}
