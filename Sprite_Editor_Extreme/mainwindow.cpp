#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto * gS  = new QGraphicsScene(ui->graphicsView);

    ui->graphicsView->setScene(gS);
    //QImage * andy = new QImage("andy.jpg"); // not sure about memory leaks here...
    // ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(*andy))); // this doesn't work anyways
    ui->graphicsView->scene()->addLine(0,0,50,50); // this works though
    ui->graphicsView->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}


