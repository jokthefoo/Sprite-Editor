#include "project.h"

Project::Project()
{
    frames.push_back(new Grid);
    workingframe=0;
    canvasSize.first=frames[workingframe]->default_width;
    canvasSize.second=frames[workingframe]->default_height;
}

Project::Project(const Project& other)
{
    this->canvasSize = other.canvasSize;
    this->workingframe = other.workingframe;
    for(auto it = other.frames.begin(); it < other.frames.end(); it++){
        Grid * grid = new Grid(**it);
        this->frames.push_back(grid);
    }
}

Project& Project::operator=(const Project& other)
{
    Project temp(other);
    swap(temp);
    return *this;
}

void Project::swap(Project& other)
{
    std::swap(frames,other.frames);
    std::swap(canvasSize,other.canvasSize);
}

Project::~Project(){
    for(auto it = frames.begin(); it < frames.end(); it++){
        delete *it;
    }
    QHash<unsigned int, QStack<Grid*>>::iterator it;
    for (it = before.begin(); it != before.end(); ++it){
        while((*it).size()) delete (*it).pop();
    }
    for (it = after.begin(); it != after.end(); ++it){
        while((*it).size()) delete (*it).pop();
    }

}

Grid * Project::getCurrentFrame(){
    return frames[workingframe];
}

void Project::addEmptyFrame(){
    Grid * grid = new Grid(); // will need to pass in the current size here.
    grid->resize(canvasSize.first,canvasSize.second);
    frames.push_back(grid);
    workingframe = frames.size()-1;
}

void Project::carryOverNewFrame(const Grid& previous){
    Grid * grid = new Grid(previous);
    frames.push_back(grid);
    workingframe = frames.size()-1;
}

void Project::deleteCurrentFrame()
{
    frames.erase(frames.begin()+workingframe);
    if(workingframe >= frames.size())
    {
        workingframe = frames.size()-1;
    }
}

void Project::setCanvasSize(int w, int h){
   canvasSize.first=w;
   canvasSize.second=h;
   for(unsigned int i = 0; i < frames.size(); i++)
   {
       frames.at(i)->resize(w,h);
   }
}

void Project::addNewFrame(Grid * grid){
    grid->resize(canvasSize.first,canvasSize.second);
    frames.push_back(grid);
    workingframe = frames.size()-1;
}

void Project::removeFrame(unsigned int frameIndex){
    frames.erase(frames.begin() + frameIndex);//might need offset of 1
    // what about changing the working frame?
}

std::vector<Grid*> Project::getAllFrames(){
    return frames;
}

void Project::changeFrame(unsigned int frameNumber){
    if(frameNumber <=  this->frames.size()){
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
     return true;
  }return false;
}

bool Project::previous(){
  if(workingframe > 0){
      workingframe--;
      return true;
  } return false;
}

QString Project::toString(){
    int height = canvasSize.second;
    int width = canvasSize.first;

    QString formatted = QString::number(height) + " " + QString::number(width) + "\n" +
            QString::number(frames.size()) + "\n";

    int frameNum = 0;
    foreach (Grid * grid, frames) {
        formatted += "Frame: " + QString::number(frameNum) + "\n";
        formatted += grid->toString();
        frameNum++;
    }
    return formatted;
}

void Project::undo(){
    bool send = before[workingframe].size()>0;
    if(send){
       after[workingframe].push(frames[workingframe]);
       frames[workingframe]=before[workingframe].pop();
    }
}

void Project::redo(){
    bool send = after[workingframe].size()>0;
    if(send){
        before[workingframe].push(frames[workingframe]);
        frames[workingframe]=after[workingframe].pop();
    }
}

void Project::addEdit(){
    Grid * temp = new Grid(frames[workingframe]->getImage());
    before[workingframe].push_back(temp);
}
