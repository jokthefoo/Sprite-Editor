#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <iostream>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene * gS  = new QGraphicsScene(ui->graphicsView);

    ui->graphicsView->setScene(gS);

    QGraphicsRectItem * item  = new QGraphicsRectItem(0,0, 256, 256);
    grid = new Grid(256,256);

    QImage * im = grid->getImage();
    im->fill(Qt::black);

    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*grid->getImage()));
    ui->graphicsView->scene()->addItem(item);
    ui->graphicsView->update();
}







void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint remapped = ui->graphicsView->mapFromParent(event->pos());
    if(ui->graphicsView->rect().contains(remapped))
    {
        QPointF mousePoint = ui->graphicsView->mapToScene(remapped);
        grid->setPixelColor(mousePoint.x(),mousePoint.y(),Qt::white);
        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*grid->getImage()));
        ui->graphicsView->scene()->update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete grid;
}


