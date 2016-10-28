#ifndef GRID_H
#define GRID_H

#include <QImage>
#include <QColor>
#include <QRgb>
#include <cmath>

class Grid
{
public:
    Grid();
    Grid(int,int);
    ~Grid();
    void resize(int, int);
    void setPixelColor(int,int,QColor);
    bool containsCoordinate(int, int);
    QImage *getImage();
private:
    int height;
    int width;

    int default_width = 500;
    int default_height = 500;

    QImage* image;
};

#endif // GRID_H
