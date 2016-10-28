#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    connectComponents();

}

void MainWindow::connectComponents(){
    QObject::connect(ui->add_Frame_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->brush_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->eraser_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->fill_Bucket_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->next_frame_button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->previous_frame_button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->zoom_In_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->zoom_Out_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->rectangle_button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->rotate_Left_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
    QObject::connect(ui->rotate_Right_Button, SIGNAL (clicked()), this, SLOT ( getButton() ));
}


void MainWindow::updateScreen(QImage * image){
    ui->graphicsView->scene()->clear();
    boundary =  new QGraphicsRectItem(0,0, image->height(), image->width());
    ui->graphicsView->scene()->addItem(boundary);
    scene->addPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->update();
}


void MainWindow::getButton(){
    QToolButton *sender = static_cast<QToolButton*>(QObject::sender());
    emit sendButtonInput(sender->objectName());
}


//void MainWindow::updateEditor(QImage *image)
//{
//    scene->addPixmap(QPixmap::fromImage(*image));
//    ui->graphicsView->update();
//}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint remapped = ui->graphicsView->mapFromGlobal(QCursor::pos()); // gives coordinates relative to parent
        QPointF  mousePoint = ui->graphicsView->mapToScene(remapped); // converts to cartesian coordinates
        if(ui->graphicsView->rect().contains(remapped))
        {
             emit sendMouseInput(mousePoint);
        }

    }
    return false;
}

//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//   QPoint remapped = ui->graphicsView->mapFromParent(event->pos()); // gives coordinates relative to parent
//    QPointF mousePoint = ui->graphicsView->mapToScene(remapped); // converts to cartesian coordinates
//    if(ui->graphicsView->rect().contains(remapped) && grid->containsCoordinate(mousePoint.x(),mousePoint.y()))
//    {
//        grid->setPixelColor(mousePoint.x(),mousePoint.y(),Qt::white);
//        updateEditor(grid->getImage());
//    }
//}

MainWindow::~MainWindow()
{
    delete ui;
}


