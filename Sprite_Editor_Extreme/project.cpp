#include "project.h"

Project::Project()
{
    currentFrame = new Grid;
    this->frames.push_back(*currentFrame);
}

Project::~Project(){
    delete currentFrame;
}

void Project::drawShapeToCurrent(int x, int y, QPolygon poly){
    //todo
}

void Project::drawToCurrent(int x, int y, QColor c){
    //todo
    if(currentFrame->containsCoordinate(x,y)){
        this->currentFrame->setPixelColor(x,y,c);
    }
}

Grid * Project::getCurrentFrame(){
    return this->currentFrame;
}

QImage * Project::getCurrentFrameImage(){
    return currentFrame->getImage();
}

void Project::redoAction(){
    //todo
}

void Project::undoAction(){
    //todo
}

void Project::changeFrame(unsigned int frameNumber){
    if(frameNumber < this->frames.size()){
        this->currentFrame=&frames[frameNumber];
    }
}
