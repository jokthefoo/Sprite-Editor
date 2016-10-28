#ifndef SPRITE_H
#define SPRITE_H
#include <vector>
#include <QPolygon>
#include <grid.h>

class Project
{
private:
    std::vector<Grid> frames;
    Grid * currentFrame;
public:
    Project();
    ~Project();
    void changeFrame(unsigned int frameNumber);
    void undoAction();
    void redoAction();
    QImage * getCurrentFrameImage();
    Grid * getCurrentFrame();
};

#endif // SPRITE_H
