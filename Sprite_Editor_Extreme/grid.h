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
    Grid(const Grid&);
    Grid & operator=(const Grid&);
    ~Grid();

    int const default_width = 16;
    int const default_height = 16;

    void swap(Grid&);
    void friend swap(Grid &,Grid &);
    void resize(int, int);
    void setPixelColor(int,int,QColor);

    QColor fromRgba(QString);
    QColor getPixelColor(int, int);
    QImage *getImage();
    QColor pixelColor(int x, int y);
    QString toString();
    QString toRgba(QColor);


    void setPixelColor(int,int,QColor, int);
    void drawPolygon(const QPointF*, int, QColor, int);
    void drawLinePixels(QPointF,QPointF,QColor, int);
    bool containsCoordinate(int, int);
    void rotateImage(int);
    void fromString(QString);
    void setBrushSize(int);
    void flipImage(QString);


protected:

    int height;
    int width;
    QImage* image;

};

#endif // GRID_H
