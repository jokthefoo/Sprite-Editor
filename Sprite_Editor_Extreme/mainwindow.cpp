#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gif.h>

#include <ui_configurationform.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Paint");
    ui->tabWidget->setTabText(1,"Transform");
    qApp->installEventFilter(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:#fffaf0");
    connectComponents();
    updateColor(Qt::white);
    setupIcons();
    setupToolTips();
    ui->framesBox->setLayout(ui->framesLayout);
    ui->scrollArea->setWidget(ui->framesBox);
    currentScale = 12;
    ui->graphicsView->scale(currentScale,currentScale);
    zoomCount = 1;
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
    setupIcon(ui->add_frame_button, ":/resources/addFrame.png");
}

void MainWindow::setupToolTips()
{
    ui->brush_Button->setToolTip("Brush Tool");
    ui->brushSize->setToolTip("Set Brush Size");
    ui->fill_Bucket_Button->setToolTip("Fill Bucket Tool");
    ui->eraser_Button->setToolTip("Eraser Tool");
    ui->rotate_Left_Button->setToolTip("Rotate sprite 90 degrees to the left");
    ui->rotate_Right_Button->setToolTip("Rotate sprite 90 degrees to the right");
    ui->zoom_In_Button->setToolTip("Zoom in");
    ui->zoom_Out_Button->setToolTip("Zoom out");
    ui->tabWidget->setTabToolTip(0, "Painting Tools");
    ui->tabWidget->setTabToolTip(1, "Transformation tools");
    ui->leftColor->setToolTip("Set color of brush");
    ui->next_frame_button->setToolTip("Next frame");
    ui->previous_frame_button->setToolTip("Previous frame");
    ui->play_button->setToolTip("Sprite Preview");
    ui->add_frame_button->setToolTip("Adds a new empty frame");
    // not working : ui->actionCanvasSize_2->setToolTip("Open configuration page");
}

void MainWindow::connectComponents(){

    QObject::connect(ui->brushSize, SIGNAL(valueChanged(int)),this, SLOT(spinnerChanged(int)));
    QObject::connect(ui->actionCanvasSize_2, SIGNAL(triggered()), this, SLOT(openConfigurationSelected()));
    QObject::connect(&configuration, SIGNAL(accepted()), this, SLOT(sendConfigurationInput()));
    QObject::connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(sendSaveAsSig()));
    QObject::connect(ui->actionOpen_project, SIGNAL(triggered()), this, SLOT(openProj()));
    QObject::connect(ui->actionExportToGif, SIGNAL(triggered()), this, SLOT(exportToGifSig()));
    QObject::connect(ui->zoom_In_Button, SIGNAL(clicked()), this, SLOT(zoomIn()));
    QObject::connect(ui->zoom_Out_Button, SIGNAL(clicked()), this, SLOT(zoomOut()));
}

void MainWindow::zoomIn()
{
    zoomCount+=1;
    currentScale += 2;
    QTransform trans;
    trans.scale(currentScale,currentScale);
    ui->graphicsView->setTransform(trans);
}

void MainWindow::zoomOut()
{
    if(zoomCount > 1)
    {
        zoomCount-=1;
        currentScale -= 2;
        QTransform trans;
        trans.scale(currentScale,currentScale);
        ui->graphicsView->setTransform(trans);
    }

}

void MainWindow::openProj()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "", "Sprite Sheet Project File (*.spp)");
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);

        for(unsigned int i = 0; i < frames.size(); i++)
        {
            ui->framesLayout->removeWidget(frames.at(i));
        }
        frames.clear();

        QString heightAndWidth = stream.readLine();
        QString numFrames = stream.readLine();
        QString frameString;
        frameString = stream.readAll();
        file.close();
        emit sendOpenProj(heightAndWidth, numFrames, frameString);
    }
}

void MainWindow::sendSaveAsSig()
{
    emit sendSaveAs();
}

void MainWindow::saveAsSelected(QString fileInfo)
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", "Sprite Sheet Project File (*.spp)");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    stream << fileInfo;
    file.close();
}

void MainWindow::exportToGifSig()
{
    emit sendExportGif();
}

void MainWindow::exportGif(std::vector<QImage> frameList)
{
    GifWriter *gifWriter = new GifWriter();
    QString filename = QFileDialog::getSaveFileName(this, "Save gif", "", "Sprite Gif File (*.gif)");
    GifBegin(gifWriter,filename.toLatin1().constData(),frameList[0].width(),frameList[0].height(),5,8,false);
    QImage image;
    for(int i = 0; i < frameList.size(); i++)
    {
        image = frameList[i];
        image = image.convertToFormat(QImage::Format_RGBA8888, Qt::OrderedDither);
        uint8_t *charAr = image.bits();
        GifWriteFrame(gifWriter,charAr,frameList[0].width(),frameList[0].height(),5,8,false);
    }
    GifEnd(gifWriter);
}

void MainWindow::openConfigurationSelected(){
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
    std::vector<Property> parse = form->parseConfigurationForm();
    std::vector<Property>::iterator i;
    for(i = parse.begin(); i != parse.end(); i++){
        emit sendPropertyChange(*i);
    }
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
    ui->framesLayout->update();
    ui->graphicsView->update();
}

void MainWindow::updateFrames(std::vector<QImage> frameList, int currentFrame)
{
    std::vector<QImage>::iterator imIt = frameList.begin();
    for(unsigned int i =0; i < frames.size(); i++)
    {
        frames.at(i)->setPixmap(QPixmap::fromImage(*imIt));
        if(i == currentFrame)
        {
            frames.at(i)->setStyleSheet("border: 2px solid yellow");
        }
        else
        {
            frames.at(i)->setStyleSheet("border: 0px solid white");
        }
        imIt++;
    }
}

void MainWindow::addFrameToLayout(QImage * image)
{
    QLabel * frame = new QLabel();
    frame->show();
    frame->setScaledContents(true);
    frame->setMinimumSize(75,75);
    frame->setMaximumSize(75,75);
    frame->setPixmap(QPixmap::fromImage(*image));
    ui->framesLayout->addWidget(frame);
    frames.push_back(frame);
}

bool MainWindow::eventFilter(QObject*, QEvent *event)
{

    //this will get all the input for every button
    if(event->type()==QEvent::MouseButtonPress){
        QWidget * child = childAt(static_cast<QMouseEvent *>(event)->pos());
        emit sendButtonInput(child);
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


PreviewWindow * MainWindow::getPreview(){
    return &preview;
}


void MainWindow::on_play_button_pressed()
{
    if(!preview.isVisible()){
        preview.show();
        //change the button icon to pause?
    }
    //else
        //call another slot which will pause the animation

}
