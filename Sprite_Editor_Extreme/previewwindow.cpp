#include "previewwindow.h"
#include "ui_previewwindow.h"

PreviewWindow::PreviewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PreviewWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);

}

PreviewWindow::~PreviewWindow()
{
    delete ui;
}

Ui::PreviewWindow * PreviewWindow::get()
{
    return this->ui;
}

void PreviewWindow::updatePreview(QImage * preview)
{
    ui->graphicsView->scene()->clear();
    boundary = new QGraphicsRectItem(0, 0, preview->height(), preview->width());
    ui->graphicsView->scene()->addItem(boundary);
    scene->addPixmap(QPixmap::fromImage(*preview));
    ui->graphicsView->update();

}
