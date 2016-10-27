#ifndef MODEL_H
#define MODEL_H
#include <QTimer>

class model // the model updates the view by sending signals
{
public:
    model();
    QTimer refresh_timer;
    //the refresh timer will send a signal to update the graphics in the view

};

#endif // MODEL_H
