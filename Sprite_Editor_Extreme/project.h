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
    void drawToCurrent(int x, int y, QColor c);
    void drawShapeToCurrent(int x, int y,QPolygon);
};

#endif // SPRITE_H
