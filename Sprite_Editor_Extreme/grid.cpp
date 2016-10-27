#include "grid.h"

Grid::Grid()
{
    height = 16;
    width = 16;
    image = new QImage(width, height, QImage::Format_ARGB32);
}

void Grid::resize(int h, int w){
    height=h;
    width=w;
}

Grid::Grid(int h,int w)
{
    if(h < 1 || h > 1080)
    {
        height = 16;
    }
    else
    {
        height = h;
    }
    if(w < 1 || w > 1920)
    {
        width = 16;
    }
    else
    {
        width = w;
    }
    image = new QImage(width, height, QImage::Format_ARGB32);

}

QImage* Grid::getImage()
{
    return image;
}

void Grid::setPixelColor(int x,int y,QColor color)
{
    image->setPixelColor(x,y,color);

}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x > 0 && y > 0 && x < width && y < height);
}

Grid::~Grid()
{
    delete image;
}
