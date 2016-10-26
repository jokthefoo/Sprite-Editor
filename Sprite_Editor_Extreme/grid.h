#ifndef GRID_H
#define GRID_H
#include <QImage>
#include <QColor>

class Grid
{
public:
    Grid();
    Grid(int,int);
    ~Grid();
    void setPixelColor(int,int,QColor);
    QImage *getImage();
private:
    int height;
    int width;
    QImage* image;
};

#endif // GRID_H
