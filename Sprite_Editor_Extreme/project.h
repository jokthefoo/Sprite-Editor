#ifndef PROJECT_H
#define PROJECT_H
#include <vector>
#include <QPolygon>
#include <grid.h>
#include <QString>
#include <QImage>
#include <QStack>
#include <grid.h>
#include <QHash>

class Project
{
private:
    std::vector<Grid*> frames;
    QHash<unsigned int,QStack<Grid*>> before;
    QHash<unsigned int,QStack<Grid*>> after;
    QPair<int,int> canvasSize;
    QPair<int,int> imageSize;
    unsigned int workingframe=0;

public:
    Project();
    ~Project();
    Project(const Project& other);
    Project& operator=(const Project&);
    void addEdit();
    void swap(Project&);
    void undo();
    void redo();
    void changeFrame(unsigned int frameNumber);
    void addNewFrame(Grid *grid);
    void removeFrame(unsigned int);
    void addEmptyFrame();
    void carryOverNewFrame(const Grid& previous);
    bool next();
    bool previous();
    std::vector<Grid*> getAllFrames();
    Grid * getCurrentFrame();
    void setCanvasSize(int,int);
    QPair<int,int> getCanvasSize();
    QString toString();
    int getWorkingFrame();
    void deleteCurrentFrame();

};

#endif // SPRITE_H
