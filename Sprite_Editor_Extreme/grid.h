#ifndef GRID_H
#define GRID_H

#include <QImage>
#include <QColor>
#include <QPainter>
#include <cmath>
#include <QString>
#include <QRegularExpression>

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
    void setPixelColor(int,int,QColor);
    QColor getPixelColor(int, int);
    bool containsCoordinate(int, int);
    QImage *getImage();
    void drawLinePixels(QPointF,QPointF,QColor);
    void rotateImage(int);
    QColor pixelColor(int x, int y);
    QString toString();
    QString toRgba(QColor);
    int const default_width = 16;
    int const default_height = 16;
    void fromString(QString);
    QColor fromRgba(QString);

protected:
    int height;
    int width;
    QImage* image;

};

#endif // GRID_H
