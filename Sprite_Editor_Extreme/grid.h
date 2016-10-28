#ifndef GRID_H
#define GRID_H

#include <QImage>
#include <QColor>
#include <QPainter>
class Grid
{
public:
    Grid();
    Grid(int,int);
    ~Grid();
    void resize(int, int);
    //void setBlockSize(int);
    void setPixelColor(int,int,QColor);
    bool containsCoordinate(int, int);
    void setDrawScale(unsigned int);
    QImage *getImage();
private:
    int height;
    int width;
    int drawScale = 1;
    int blocksize = 4;
    int default_width = 256;
    int default_height = 256;
    QImage* image;
};

#endif // GRID_H
