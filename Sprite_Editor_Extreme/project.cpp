#include "project.h"

Project::Project()
{
    currentFrame = new Grid;
    frames.push_back(*currentFrame);
}

Project::~Project(){
    delete currentFrame;
}

Grid * Project::getCurrentFrame(){
    return currentFrame;
}

void Project::addEmptyFrame(){

}

void Project::setCanvasSize(int w, int h){
   canvasSize.first=w;
   canvasSize.second=h;
   currentFrame->resize(w,h);
}

void Project::addNewFrame(Grid *){

}

void Project::removeFrame(unsigned int){

}

std::vector<Grid> Project::getAllFrames(){
    return frames;
}

void Project::changeFrame(unsigned int frameNumber){
    if(frameNumber < this->frames.size()){
        this->currentFrame=&frames[frameNumber];
    }
}
