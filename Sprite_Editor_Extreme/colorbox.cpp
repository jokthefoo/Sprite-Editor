#include "colorbox.h"

ColorBox::ColorBox(QWidget* parent) : QLabel(parent)
{

}

void ColorBox::mousePressEvent(QMouseEvent * event) {
    std::cout << "rawr" << std::endl;
    emit clicked();
}

ColorBox::~ColorBox(){

}
