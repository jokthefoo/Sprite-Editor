#include "grid.h"

Grid::Grid()
{
    height = default_height;
    width = default_width;
    image = new QImage(width, height, QImage::Format_ARGB32);
    image->fill(Qt::white);

}

Grid::Grid(const Grid& other){
    this->image = new QImage;
    *this->image = other.image->copy();
    this->height=other.height;
    this->width=other.width;
}

Grid::Grid(QImage *image){
    this->image = new QImage;
    *this->image = image->copy();
    this->height=image->height();
    this->width=image->width();
}

Grid& Grid::operator=(const Grid& other)
{
    Grid temp(other);
    this->swap(temp);
    return *this;
}

void Grid::swap(Grid& other){
    this->image->swap(*(other.image));
    std::swap(height,other.height);
    std::swap(width,other.width);
}

void swap(Grid& first, Grid& second){
    first.swap(second);
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
    image->fill(Qt::white);
}

void Grid::resize(int h, int w){
    height=h;
    width=w;
    QImage * newImage = new QImage(h,w,QImage::Format_ARGB32);
    newImage->fill(Qt::white);
    QPainter painter(newImage);
    painter.drawImage(0,0,*image);
    painter.end();
    image = newImage;
}

QImage* Grid::getImage()
{
    return image;
}

//void Grid::setDrawScale(unsigned int scaleFactor){
//drawScale=scaleFactor+2;
//}

void Grid::rotateImage(int degrees)
{
    QTransform trans;
    trans.rotate(degrees);
    *image = image->transformed(trans);
}

void Grid::flipImage(QString horOrVert)
{
    if(horOrVert == "hor")
    {
        *image = image->mirrored(true,false);
    }else
    {
        *image = image->mirrored(false,true);
    }
}

void Grid::setPixelColor(int x,int y,QColor color, int brushSize)
{
    QPainter painter;
    QPen pen;

    if(containsCoordinate(x,y)){
        painter.begin(image);
        pen.setWidth(brushSize);
        pen.setColor(color);
        painter.setPen(pen);
        painter.drawPoint(x,y);
        painter.end();
    }

}

void Grid::drawPolygon(const QPointF* points, int pointCount, QColor color, int brushSize)
{
    QPainter painter;
    QPen pen;

    painter.begin(image);
    pen.setWidth(brushSize);
    pen.setColor(color);
    painter.setPen(pen);
    painter.drawPolygon(points, pointCount);
    painter.end();

}

QColor Grid::getPixelColor(int x, int y){
    return image->pixelColor(x, y);
}

void Grid::drawLinePixels(QPointF lastPoint,QPointF endPoint,QColor color, int brushSize)
{
    QPainter painter;
    QPen pen;

    if(containsCoordinate(lastPoint.x(),lastPoint.y()) && containsCoordinate(endPoint.x(),endPoint.y())){
        painter.begin(image);
        pen.setWidth(brushSize);
        pen.setColor(color);
        painter.setPen(pen);
        painter.drawLine(lastPoint, endPoint);
        painter.end();
    }

}

bool Grid::containsCoordinate(int x, int y){ // uses cartesian coordinates from top left
     return (x <= width&&y<=height);
}

void Grid::fromString(QString frame){
    QStringList pixels;
    pixels = frame.split(QRegularExpression("\\s+"));
    QStringList::iterator it = pixels.begin();
    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            QColor color = fromRgba(*it);
            setPixelColor(x,y,color,1);
            it++;
        }
    }
}

QColor Grid::fromRgba(QString color){

    int r = 0,g = 0,b = 0,a = 0;
    r = color.left(3).toInt();
    g = color.mid(3,3).toInt();
    b = color.mid(6,3).toInt();
    a = color.mid(9,3).toInt();

    return QColor (r,g,b,a);
}

QString Grid::toString(){
    QString formatted;
    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            QColor color = getPixelColor(x, y);
            formatted += toRgba(color);
        }
        formatted += "\n";
    }
    return formatted;
}

QString Grid::toRgba(QColor color){
    QString red,green,blue,alpha;
       if(color.red() < 100 && color.red() > 9)
       {
           red = "0" + QString::number(color.red());
       }
       else if(color.red() < 10)
       {
           red =  "00" + QString::number(color.red());
       }
       else
       {
           red = QString::number(color.red());
       }

       if(color.green() < 100 && color.green() > 9)
       {
           green = "0" + QString::number(color.green());
       }
       else if(color.green() < 10)
       {
           green =  "00" + QString::number(color.green());
       }
       else
       {
           green = QString::number(color.green());
       }

       if(color.blue() < 100 && color.blue() > 9)
       {
           blue = "0" + QString::number(color.blue());
       }
       else if(color.blue() < 10)
       {
           blue =  "00" + QString::number(color.blue());
       }
       else
       {
           blue = QString::number(color.blue());
       }

       if(color.alpha() < 100 && color.alpha() > 9)
       {
           alpha = "0" + QString::number(color.alpha());
       }
       else if(color.alpha() < 10)
       {
           alpha =  "00" + QString::number(color.alpha());
       }
       else
       {
           alpha = QString::number(color.alpha());
       }
       return red + green + blue + alpha + " ";
   }

Grid::~Grid()
{
    if(image!=nullptr) delete image;
}

QColor Grid::pixelColor(int x, int y)
{
    return QColor(image->pixel(x, y));
}
