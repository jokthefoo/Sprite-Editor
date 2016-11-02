#ifndef PROJECT_H
#define PROJECT_H
#include <vector>
#include <QPolygon>
#include <grid.h>
#include <QString>

class Project
{
private:
    std::vector<Grid> frames;
    Grid * currentFrame;
    QPair<int,int> canvasSize;
    QPair<int,int> imageSize;
    unsigned int workingframe=0;
public:
    Project();
    Project(int,int,int);
    Project(const Project& other);
    Project& operator=(const Project&);
    void swap(Project&);
    ~Project();
    void changeFrame(unsigned int frameNumber);
    void addNewFrame(Grid *grid);
    void removeFrame(unsigned int);
    void addEmptyFrame();
    bool next();
    bool previous();
    std::vector<Grid> getAllFrames();
    Grid * getCurrentFrame();
    void setCanvasSize(int,int);
    QPair<int,int> getCanvasSize();
    QPair<int,int> getImageSize();
    QString toString();
    int getWorkingFrame();
    void deleteCurrentFrame();

};

#endif // SPRITE_H
