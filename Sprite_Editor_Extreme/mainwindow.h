#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPalette>
#include <QGraphicsRectItem>
#include <QImage>
#include <QToolButton>
#include <grid.h>
#include <iostream>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateEditor(QImage * image);
    ~MainWindow();

signals:
    void sendMouseInput(QPointF, QEvent*);
    void sendButtonInput(QToolButton*);
    void sendColorChange(QLabel*);
    void sendPropertyChange(QString property, std::vector<int>);


public slots:
    void propertyChangedMenu(bool);
    void propertyChangedSpinner(int);
    void buttonInput();
    void labelInput();
    void updateScreen(QImage * toShow);
    void updateColor(QColor); // left is false right is true
    // void updatePreview(std::vector<Grid>);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    void connectComponents();
    void setupIcons();
    QGraphicsRectItem * boundary; // should move this to the model
    Ui::MainWindow * ui;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
