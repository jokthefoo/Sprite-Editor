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

void Project::addNewFrame(Grid *){


}

void Project::removeFrame(unsigned int i){


}

std::vector<Grid> Project::getAllFrames(){
    return frames;
}

void Project::changeFrame(unsigned int frameNumber){
    if(frameNumber < this->frames.size()){
        this->currentFrame=&frames[frameNumber];
    }
}
