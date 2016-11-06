#include "history.h"

History::History()
{



}
History::~History(){


}

Grid& History::getCurrent(){
  return current[currentFrame];
}

void History::addEdit(QImage *image){
    before[currentFrame].push(current[currentFrame]);
    current[currentFrame]=Grid(image);
}

Grid History::back(){
   bool send = before[currentFrame].size()>0;
   if(send){
      after[currentFrame].push(current[currentFrame]);
      current[currentFrame]=before[currentFrame].pop();
   }
   return current[currentFrame];
}

Grid History::foward(){
   bool send = after[currentFrame].size()>0;
   if(send){
       before[currentFrame].push(current[currentFrame]);
       current[currentFrame]=after[currentFrame].pop();
   }
   return current[currentFrame];
}

void History::changeFrame(unsigned int i){
   if(after.size()>i){
       currentFrame=i;

   }
}
