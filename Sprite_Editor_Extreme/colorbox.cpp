#include "colorbox.h"

ColorBox::ColorBox(QWidget* parent) : QLabel(parent)
{

}

void ColorBox::mousePressEvent(QMouseEvent * event) {
    emit clicked();
}

ColorBox::~ColorBox(){

}
