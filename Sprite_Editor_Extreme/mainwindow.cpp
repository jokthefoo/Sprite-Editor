#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    connectComponents();
    ColorChange(Qt::white);

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
    QObject::connect(ui->leftColor, SIGNAL (clicked()), this, SLOT ( getLabel() ));
}


void MainWindow::ColorChange(QColor color){
// side is for right and left click. no need to worry about it now.
    QPalette p(palette());
    p.setColor(QPalette::Foreground,color);
    QString temp("background-color:"+color.name());
    ui->leftColor->setStyleSheet(temp);
    ui->leftColor->update();
}


void MainWindow::updateScreen(QImage * image){
    ui->graphicsView->scene()->clear();
    boundary =  new QGraphicsRectItem(0,0, image->height(), image->width());
    ui->graphicsView->scene()->addItem(boundary);
    scene->addPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->update();
}


void MainWindow::getLabel(){
    QLabel *sender = static_cast<QLabel*>(QObject::sender());
    emit sendLabelInput(sender);
}

void MainWindow::getButton(){
    QToolButton *sender = static_cast<QToolButton*>(QObject::sender());
    emit sendButtonInput(sender);
}

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

MainWindow::~MainWindow()
{
    delete ui;
}


