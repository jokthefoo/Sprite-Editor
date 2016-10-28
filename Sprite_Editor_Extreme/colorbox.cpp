#include "colorbox.h"
#include <QWidget>
#include <iostream>

ColorBox::ColorBox(QWidget* parent) : QLabel(parent)
{

}
void ColorBox::mousePressEvent(QMouseEvent * event) {
    std::cout << "rawr" << std::endl;
    emit clicked();
}
ColorBox::~ColorBox(){

}
