#include "grid.h"

Grid::Grid()
{
    height = default_height;
    width = default_width;
    image = new QImage(width, height, QImage::Format_ARGB32);
    image->fill(Qt::black);
}

void Grid::resize(int h, int w){
    height=h;
    width=w;
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

QImage* Grid::getImage()
{
    return image;
}

void Grid::setPixelColor(int x,int y,QColor color)
{
    QPainter painter;
    QPen pen;

    x = x - x%blocksize;
    y = y - y%blocksize;

    if(this->containsCoordinate(x,y)){
        painter.begin(image);
        pen.setWidth(blocksize);
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.drawPoint(x,y);
        painter.end();
        //image->setPixelColor(x,y,color);
    }

}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x > 0 && y > 0 && x < width && y < height);
}



Grid::~Grid()
{
    delete image;
}
