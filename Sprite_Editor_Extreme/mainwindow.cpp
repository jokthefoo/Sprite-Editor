#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene * gS  = new QGraphicsScene(ui->graphicsView);

    ui->graphicsView->setScene(gS);
    //ui->graphicsView->scene()->addPixmap(QPixmap("://andy.png")); // in order for this to work, the file must be added to the resources file
    //ui->graphicsView->scene()->addLine(0,0,50,50); // this works though
    ui->graphicsView->update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint remapped = ui->graphicsView->mapFromParent(event->pos());
    if(ui->graphicsView->rect().contains(remapped))
    {
        QPointF mousePoint = ui->graphicsView->mapToScene(remapped);

        Grid grid(256,256);
        QColor color(255,255,255);
        grid.setPixelColor(mousePoint.x(),mousePoint.y(),color);

        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*grid.getImage()));
        ui->graphicsView->update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


