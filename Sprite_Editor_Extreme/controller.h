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
    QTimer timer;
    std::atomic_bool drawing;
    std::atomic_bool allowDrawing;
    bool addBlankFrame = true;
    void decodeAction(QString);

public:
    Controller();
    Controller(MainWindow*);
    ~Controller();
    void sendAllFrame();

signals:
    void sendImage(QImage *);
    void sendPreviewImage(QImage *);
    void sendColor(QColor);
    void sendFrames(std::vector<QImage>, int);
    void sendFramesForExport(std::vector<QImage>);
    void saveAs(QString);
    void sendNewFrame(QImage *);
    void sendActiveTool(int);
    void sendDeleteFrame(int);

public slots:
    void receiveExport();
    void receiveButtonInput(QWidget*);
    void receiveMouseInput(QPointF, QMouseEvent*);
    void receivePropertyChange(Property);
    void receiveSaveAs();
    void receiveOpenProj(QString,QString,QString);
    void timeoutSendImage();
    void disableDraw();
    void enableDraw();
};

#endif // CONTROLLER_H
