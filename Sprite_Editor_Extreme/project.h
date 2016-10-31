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
    QPair<int,int> canvasSize;
    QPair<int,int> imageSize;
public:
    Project();
    ~Project();
    void changeFrame(unsigned int frameNumber);
    void addNewFrame(Grid *grid);
    void removeFrame(unsigned int);
    void addEmptyFrame();
    std::vector<Grid> getAllFrames();
    Grid * getCurrentFrame();
    void setCanvasSize(int,int);
    QPair<int,int> getCanvasSize();
    QPair<int,int> getImageSize();

};

#endif // SPRITE_H
