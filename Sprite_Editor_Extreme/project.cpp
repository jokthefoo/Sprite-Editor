#include "project.h"

Project::Project()
{
    Grid grid;
    frames.push_back(grid);
    currentFrame = &frames.front();
}

Project::~Project(){
}

Grid * Project::getCurrentFrame(){
    return currentFrame;
}

void Project::addEmptyFrame(){
    Grid * grid = new Grid; // will need to pass in the current size here.
    frames[workingframe]=*currentFrame; // save the current state
    frames.push_back(*grid);
    workingframe = frames.size()-1;
    currentFrame = &frames[workingframe];

}

void Project::setCanvasSize(int w, int h){
   canvasSize.first=w;
   canvasSize.second=h;
   currentFrame->resize(w,h);
}

void Project::addNewFrame(Grid * grid){
    frames[workingframe]=*currentFrame;
    frames.push_back(*grid);
    workingframe = frames.size()-1;
    currentFrame = &frames[workingframe];
}

void Project::removeFrame(unsigned int frameIndex){
    frames.erase(frames.begin() + frameIndex);//might need offset of 1

}

std::vector<Grid> Project::getAllFrames(){
  frames[workingframe]=*currentFrame;
  return frames;
}

void Project::changeFrame(unsigned int frameNumber){
    if(frameNumber < this->frames.size()){
         this->currentFrame=&frames[frameNumber];
         workingframe=frameNumber;
    }
}


bool Project::next(){
  if(workingframe+1< frames.size())
  {
     workingframe++;
     currentFrame = &frames[workingframe];
     return true;
  }return false;
}

bool Project::previous(){
  if(workingframe > 0){
      workingframe--;
      currentFrame = &frames[workingframe];
      return true;
  } return false;
}

QString Project::toString(){
    int height = canvasSize.second;
    int width = canvasSize.first;

    QString formatted = QString::number(height) + " " + QString::number(width) + "\n" +
            QString::number(frames.size()) + "\n";

    foreach (Grid* grid, frames) {
        formatted += grid->toString();
    }
    return formatted;
}


