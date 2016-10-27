#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    boundary =  new QGraphicsRectItem(0,0, default_width, default_height);
    grid = new Grid(default_width,default_height);

    QImage * im = grid->getImage();
    im->fill(Qt::black);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->addItem(boundary);

    updateEditor(grid->getImage());

}


void MainWindow::updateEditor(QImage *image){
    scene->addPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint remapped = ui->graphicsView->mapFromParent(event->pos()); // gives coordinates relative to parent
    QPointF mousePoint = ui->graphicsView->mapToScene(remapped); // converts to cartesian coordinates
    if(ui->graphicsView->rect().contains(remapped) && grid->containsCoordinate(mousePoint.x(),mousePoint.y()))
    {
        grid->setPixelColor(mousePoint.x(),mousePoint.y(),Qt::white);
        updateEditor(grid->getImage());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete grid;
}


