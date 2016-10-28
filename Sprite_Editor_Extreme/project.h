#ifndef PROJECT_H
#define PROJECT_H
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
    void addNewFrame(Grid *);
    void removeFrame(unsigned int);
    void addEmptyFrame();
    std::vector<Grid> getAllFrames();
    Grid * getCurrentFrame();
};

#endif // SPRITE_H
