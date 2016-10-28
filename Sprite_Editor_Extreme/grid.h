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
    void setPixelColor(int,int,QColor);

    bool containsCoordinate(int, int);
    QImage *getImage();
private:
    int height;
    int width;
    int rows;
    int columns;
    int blocksize = 16;

    int default_width = 256;
    int default_height = 256;

    QPoint snapToGrid(int x, int y);
    QImage* image;
};

#endif // GRID_H
