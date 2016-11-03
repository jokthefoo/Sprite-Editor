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
<<<<<<< HEAD
    void setPixelColor(int,int,QColor);

    QImage *getImage();
    QColor getPixelColor(int, int);
    QColor fromRgba(QString);
=======
    void setPixelColor(int,int,QColor, int);
    void drawPolygon(const QPointF*, int, QColor, int);
    QColor getPixelColor(int, int);
    bool containsCoordinate(int, int);
    QImage *getImage();
    void drawLinePixels(QPointF,QPointF,QColor, int);
    void rotateImage(int);
>>>>>>> a1b3a42c8bea58bd58e5c1c815bde2565206cf38
    QColor pixelColor(int x, int y);
    QString toString();
    QString toRgba(QColor);
    bool containsCoordinate(int, int);

    void drawLinePixels(QPointF,QPointF,QColor);
    void rotateImage(int);
    void fromString(QString);
<<<<<<< HEAD

    History history;
=======
    QColor fromRgba(QString);
    void setBrushSize(int);
    void flipImage(QString);
>>>>>>> a1b3a42c8bea58bd58e5c1c815bde2565206cf38

protected:

    int height;
    int width;
    QImage* image;

};

#endif // GRID_H
