#include "grid.h"

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
    QImage newImage(h,w,QImage::Format_ARGB32);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0),*image);
    painter.end();
    image->swap(newImage);
}

QImage* Grid::getImage()
{
    return image;
}

void Grid::setDrawScale(unsigned int scaleFactor){
    drawScale=scaleFactor+2;
}

void Grid::rotateImage(int degrees)
{
    QTransform trans;
    trans.rotate(degrees);
    *image = image->transformed(trans);
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

void Grid::drawLinePixels(QPointF lastPoint,QPointF endPoint,QColor color)
{
    QPainter painter;
    QPen pen;

    int x = lastPoint.x();
    int y = lastPoint.y();
    lastPoint.setX(x - x %blocksize);
    lastPoint.setY(y - y %blocksize);
    x = endPoint.x();
    y = endPoint.y();
    endPoint.setX(x - x %blocksize);
    endPoint.setY(y - y %blocksize);

    if(containsCoordinate(lastPoint.x(),lastPoint.y()) && containsCoordinate(endPoint.x(),endPoint.y())){
        painter.begin(image);// the scaling and canvas stuff needs work.
        pen.setWidth(pow(2,drawScale));
        pen.setColor(color);
        painter.setPen(pen);
        painter.drawLine(lastPoint, endPoint);
        painter.end();
        //image->setPixelColor(x,y,color);
    }

}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x <= width&&y<=height);
}

Grid::~Grid()
{
    if(image!=nullptr) delete image;
}
