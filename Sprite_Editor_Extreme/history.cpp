#include "history.h"


History::~History(){
    while(!stacka.empty()) delete stacka.pop();
    while(!stackb.empty()) delete stackb.pop();
}
History::History()
{
}

bool History::backwards(){
   if(stacka.size()>0){
       stackb.push(current);
       current = stacka.pop();
       return true;
   } return false;
}

bool History::forwards(){
    if(stackb.size()>0){
        stacka.push(current);
        current = stackb.pop();
        return true;
    }return false;
}

void History::addEdit(Grid grid){
    Grid * temp = new Grid(grid);
    stackb.push(current);
    current = temp;
}

Grid * History::getCurrent(){
   return current;
}

