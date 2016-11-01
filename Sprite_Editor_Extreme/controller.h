#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QMouseEvent>
#include <QToolButton>
#include <QLabel>
#include <QTimer>
#include <QColorDialog>
#include <vector>
#include <model.h>
#include <mainwindow.h>
#include <QRegularExpression>

// following the mvc design pattern : https://en.wikipedia.org/wiki/Model-view-controller
class Controller : public QObject
{
    Q_OBJECT

private:
    Model* model;
    bool drawing;

public:
    Controller();
    Controller(MainWindow*);
    QTimer timer;
    ~Controller();
    //should have slots to capture the input from the user and then will use the model to change
    //the current states.

signals:
    void sendImage(QImage *);
    void sendPreviewImage(QImage *);
    void sendColor(QColor);
    void saveAs(QString);

public slots:
    void receiveButtonInput(QWidget*);
    void receiveMouseInput(QPointF, QMouseEvent*);
    void receivePropertyChange(Property);
    void timeoutSendImage();
    void receiveSaveAs();
    void receiveOpenProj(QString,QString,QString);
};

#endif // CONTROLLER_H
