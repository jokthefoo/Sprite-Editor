#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QAction>
#include <ui_configurationform.h>
#include <typeinfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    qApp->installEventFilter(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:#fffaf0");
    connectComponents();
    updateColor(Qt::white);
    setupIcons();

}

void static setupIcon(QToolButton * button, QString filename){

    QPixmap map(filename);
    QIcon icon(map);
    button->setIcon(icon);
    button->setIconSize(map.rect().size());
}

void MainWindow::setupIcons(){

    setupIcon(ui->brush_Button, ":/resources/brush.png");
    setupIcon(ui->eraser_Button, ":/resources/eraser.png");
    setupIcon(ui->rotate_Left_Button,":/resources/rotateLeft.png");
    setupIcon(ui->rotate_Right_Button,":/resources/rotateRight.png");
    setupIcon(ui->zoom_In_Button,":/resources/zoomin.png");
    setupIcon(ui->zoom_Out_Button,":/resources/zoomout.png");
    setupIcon(ui->fill_Bucket_Button,":/resources/bucket.png");
    setupIcon(ui->next_frame_button,":/resources/forward.png");
    setupIcon(ui->previous_frame_button,":/resources/back.png");
    setupIcon(ui->play_button, ":/resources/play.png");
    setupIcon(ui->rectangle_button, ":/resources/polygon.png");
    setupIcon(ui->add_Frame_Button, ":/resources/addFrame.png");

}

void MainWindow::connectComponents(){

    QObject::connect(ui->leftColor, SIGNAL (clicked()), this, SLOT ( sendLabelInput() ));
    QObject::connect(ui->brushSize, SIGNAL(valueChanged(int)),this, SLOT(spinnerChanged(int)));
    QObject::connect(ui->actionCanvasSize_2, SIGNAL(triggered()), this, SLOT(openConfigurationSelected()));
    QObject::connect(&configuration, SIGNAL(accepted()), this, SLOT(sendConfigurationInput()));

}

void MainWindow::openConfigurationSelected(){
     QAction * action = static_cast<QAction*>(QObject::sender());
     //send the property change once the canvas stuff is figured out
     this->configuration.show();
     this->configuration.raise();

}

void MainWindow::spinnerChanged(int value)
{
    QSpinBox * spin = static_cast<QSpinBox*>(QObject::sender());

    Property tosend(spin->objectName());
    tosend.addValue(value);
    emit sendPropertyChange(tosend);
}

void MainWindow::sendConfigurationInput(){
    ConfigurationForm * form = static_cast<ConfigurationForm*>(QObject::sender());
    //std::cout << "testr" << std::endl;
    bool ok;
    bool alsoOk;
    int cwparse = form->get()->canvasWidthEdit->text().toInt(&alsoOk); // parse text from here
    int chparse = form->get()->canvasHeightEdit->text().toInt(&ok);

    if(ok&&alsoOk){
        Property tosend("canvasSize");
        tosend.addValue(cwparse);
        tosend.addValue(chparse);
        emit sendPropertyChange(tosend);
    }// else the input was invalid
}

void MainWindow::sendLabelInput(){ // could merge
    QLabel *sender = static_cast<QLabel*>(QObject::sender());
    emit sendColorChange(sender);
}


void MainWindow::updateColor(QColor color){
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

bool MainWindow::eventFilter(QObject* obj, QEvent *event)
{

    //this will get all the input for every button
    if(event->type()==QEvent::MouseButtonPress){
        QWidget * child = childAt(static_cast<QMouseEvent *>(event)->pos());
        QToolButton * button = dynamic_cast<QToolButton*>(child);
        if(button!=NULL){
            emit sendButtonInput(button);
        }
    }

    if(event->type()==QEvent::MouseButtonPress||event->type()==QEvent::MouseMove||event->type()==QEvent::MouseButtonRelease){
        QPoint remapped = ui->graphicsView->mapFromGlobal(QCursor::pos()); // gives coordinates relative to parent
        QPointF  mousePoint = ui->graphicsView->mapToScene(remapped); // converts to cartesian coordinates
        if(ui->graphicsView->rect().contains(remapped))
        {
             emit sendMouseInput(mousePoint, static_cast<QMouseEvent*>(event));
        }
    }

    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

