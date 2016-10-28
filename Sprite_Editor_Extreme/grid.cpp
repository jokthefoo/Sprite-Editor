#include "grid.h"

Grid::Grid()
{
    height = default_height;
    width = default_width;
    image = new QImage(width, height, QImage::Format_ARGB32);
    image->fill(Qt::white);
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
    if(this->containsCoordinate(x,y)){
        x = x - (x%5);
        y = y - (y%5);

        int saveY = y;

        for(int i = 0; i < 5; i++)
        {
           y=saveY;
           for(int j = 0; j < 5; j++)
           {
               image->setPixelColor(x, y, color);
               y++;
           }
           x++;

        }
    }
}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x > 0 && y > 0 && x < width && y < height);
}

Grid::~Grid()
{
    delete image;
}
