#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto * gS  = new QGraphicsScene(ui->graphicsView);

    ui->graphicsView->setScene(gS);
    ui->graphicsView->scene()->addPixmap(QPixmap("://andy.png")); // in order for this to work, the file must be added to the resources file
    ui->graphicsView->scene()->addLine(0,0,50,50); // this works though
    ui->graphicsView->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}


