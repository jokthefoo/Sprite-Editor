#include "model.h"

Model::Model()
{

}

Model::~Model(){

}

Grid * Model::getCurrentFrame(){
    return this->project.getCurrentFrame();
}

QImage * Model::getCurrentFrameImage(){
    return this->project.getCurrentFrameImage();
}
