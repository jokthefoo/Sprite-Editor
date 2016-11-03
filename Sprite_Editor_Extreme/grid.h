#ifndef GRID_H
#define GRID_H

#include <QImage>
#include <QColor>
#include <QPainter>
#include <cmath>
#include <QString>
#include <QRegularExpression>
#include <history.h>

class Grid
{
public:
    Grid();
    Grid(int,int);
    Grid(const Grid&);
    Grid & operator=(const Grid&);
    ~Grid();

    int const default_width = 16;
    int const default_height = 16;

    void swap(Grid&);
    void friend swap(Grid &,Grid &);
    void resize(int, int);
    void setPixelColor(int,int,QColor);

    QImage *getImage();
    QColor getPixelColor(int, int);
    QColor fromRgba(QString);
    QColor pixelColor(int x, int y);
    QString toString();
    QString toRgba(QColor);
    bool containsCoordinate(int, int);

    void drawLinePixels(QPointF,QPointF,QColor);
    void rotateImage(int);
    void fromString(QString);

    History history;

protected:

    int height;
    int width;
    QImage* image;

};

#endif // GRID_H
