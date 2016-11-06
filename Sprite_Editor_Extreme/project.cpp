#include "project.h"

Project::Project()
{
    currentFrame = new Grid;
    frames.push_back(*currentFrame);
    canvasSize.first=currentFrame->default_width;
    canvasSize.second=currentFrame->default_height;
}

Project::Project(int h, int w, int numFrames)
{
    Grid *grid;
    canvasSize.first=w;
    canvasSize.second=h;
    for(int x = 0; x < numFrames; x++)
    {
        grid = new Grid(h,w);
        frames.push_back(*grid);
    }
    currentFrame = &frames.front();
}

Project::Project(const Project& other)
{

    this->canvasSize = other.canvasSize;
    this->currentFrame = other.currentFrame;
    for(auto it = other.frames.begin(); it < other.frames.end(); it++){
        Grid grid(*it);
        this->frames.push_back(grid);
    }
}

Project& Project::operator=(const Project& other)
{
    Project temp(other);
    this->swap(temp);
    return *this;
}

void Project::swap(Project& other)
{
    std::swap(canvasSize,other.canvasSize);
    std::swap(currentFrame,other.currentFrame);
    std::swap(frames,other.frames);
}

Project::~Project(){
    delete currentFrame;
}

Grid * Project::getCurrentFrame(){
    return currentFrame;
}

void Project::addEmptyFrame(){
    Grid * grid = new Grid(); // will need to pass in the current size here.
    grid->resize(canvasSize.first,canvasSize.second);
    frames[workingframe]=*currentFrame; // save the current state
    frames.push_back(*grid);
    workingframe = frames.size()-1;
    currentFrame = &frames[workingframe];

}

void Project::carryOverNewFrame(const Grid& previous){
    Grid * grid = new Grid(previous);
    frames[workingframe]=*currentFrame; // save the current state
    frames.push_back(*grid);
    workingframe = frames.size()-1;
    currentFrame = &frames[workingframe];
}

void Project::deleteCurrentFrame()
{
    frames.erase(frames.begin()+workingframe);
    if(workingframe >= frames.size())
    {
        workingframe = frames.size()-1;
    }
    currentFrame = &frames[workingframe];
}

void Project::setCanvasSize(int w, int h){
   canvasSize.first=w;
   canvasSize.second=h;
   for(int i = 0; i < frames.size(); i++)
   {
       frames.at(i).resize(w,h);
   }
   currentFrame->resize(w,h);
   for(std::vector<Grid>::iterator it = frames.begin(); it < frames.end(); ++it){
       it->resize(w,h);
   }
   frames[workingframe]=*currentFrame;
}

void Project::addNewFrame(Grid * grid){
    grid->resize(canvasSize.first,canvasSize.second);
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

int Project::getWorkingFrame()
{
    return workingframe;
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
    frames[workingframe]=*currentFrame;
    int height = canvasSize.second;
    int width = canvasSize.first;

    QString formatted = QString::number(height) + " " + QString::number(width) + "\n" +
            QString::number(frames.size()) + "\n";

    int frameNum = 0;
    foreach (Grid grid, frames) {
        formatted += "Frame: " + QString::number(frameNum) + "\n";
        formatted += grid.toString();
        frameNum++;
    }
    return formatted;
}


