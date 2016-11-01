#ifndef GRID_H
#define GRID_H

#include <QImage>
#include <QColor>
#include <QPainter>
#include <cmath>
#include <QString>

class Grid
{
public:
    Grid();
    Grid(int,int);
    ~Grid();
    Grid(const Grid&);
    Grid & operator=(const Grid&);
    void swap(Grid&);
    void friend swap(Grid &,Grid &);
    void resize(int, int);
    //void setBlockSize(int);
    void setPixelColor(int,int,QColor);
    QColor getPixelColor(int, int);
    bool containsCoordinate(int, int);
    void setDrawScale(unsigned int);
    QImage *getImage();
    void drawLinePixels(QPointF,QPointF,QColor);
<<<<<<< HEAD
    void rotateImage(int);
    QColor pixelColor(int x, int y);
private:
=======
    void rotateImage(int );
    QString toString();
    QString toRgba(QColor);

protected:
>>>>>>> refs/remotes/origin/frameintegration
    const int initScaleFactor = 3;
    int height;
    int width;
    int drawScale = initScaleFactor;
    int blocksize = std::pow(2,initScaleFactor);
    int default_width = 256;
    int default_height = 256;
    QImage* image;

};

#endif // GRID_H
