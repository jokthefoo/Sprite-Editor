#include "grid.h"
#include <QRgb>
Grid::Grid()
{
    height = 16;
    width = 16;
    image = new QImage(width, height, QImage::Format_ARGB32);
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

Grid::~Grid()
{
    delete image;
}
