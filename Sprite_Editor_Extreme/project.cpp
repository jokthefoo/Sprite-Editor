#include "project.h"

Project::Project()
{

}

void Project::drawShapeToCurrent(int x, int y, QPolygon poly){
    //todo
}

void Project::drawToCurrent(int x, int y, QColor c){
    //todo
    this->currentFrame->setPixelColor(x,y,c);
}

void Project::redoAction(){
    //todo
}

void Project::undoAction(){
    //todo
}

void Project::changeFrame(int frameNumber){
    if(frameNumber < this->frames.size()){
        this->currentFrame=&frames[frameNumber];
    }
}
