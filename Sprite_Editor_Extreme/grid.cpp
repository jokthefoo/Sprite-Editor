#include "grid.h"
#include <cmath>

Grid::Grid()
{
    height = default_height;
    width = default_width;
    image = new QImage(width, height, QImage::Format_ARGB32);
    image->fill(Qt::black);
}

Grid::Grid(int h,int w)
{
    if(h < 1 || h > 1080)
    {
        height = default_height;
    }
    else
    {
        height = h;
    }
    if(w < 1 || w > 1920)
    {
       width = default_width;;
    }
    else
    {
        width = w;
    }
    image = new QImage(width, height, QImage::Format_ARGB32);

}

void Grid::resize(int h, int w){
    height=h;
    width=w;
}

QImage* Grid::getImage()
{
    return image;
}

void Grid::setDrawScale(unsigned int scaleFactor){
    drawScale=scaleFactor;
}


void Grid::setPixelColor(int x,int y,QColor color)
{
    QPainter painter;
    QPen pen;

    x = x - x %blocksize;
    y = y - y %blocksize;

    if(containsCoordinate(x,y)){
        painter.begin(image);// the scaling and canvas stuff needs work.
        pen.setWidth(pow(2,drawScale));
        pen.setColor(color);
        painter.setPen(pen);
        painter.drawPoint(x,y);
        painter.end();
        //image->setPixelColor(x,y,color);
    }

}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x < width && y < height);
}

Grid::~Grid()
{
    if(image!=nullptr) delete image;
}
