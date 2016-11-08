#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gif.h>
#include <QClipboard>
#include <qdebug.h>

#include <ui_configurationform.h>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Paint");
    ui->tabWidget->setTabText(1,"Transform");
    ui->tabWidget->setCurrentIndex(0);
    qApp->installEventFilter(this);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:#d3d3d3");
    connectComponents();
    updateColor(Qt::white);
    setupIcons();
    setupToolTips();
    ui->framesBox->setLayout(ui->framesLayout);
    ui->scrollArea->setWidget(ui->framesBox);
    currentScale = 12;
    ui->graphicsView->scale(currentScale,currentScale);
    zoomCount = 6;
}

void static setupIcon(QToolButton *button, QString filename){
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
    setupIcon(ui->flip_Horizontally, ":/resources/flipHorz.png");
    setupIcon(ui->flip_Vertically, ":/resources/flipVert.png");
    setupIcon(ui->undo_button, ":/resources/undo.png");
    setupIcon(ui->redo_button, ":/resources/redo.png");
}

void MainWindow::setupToolTips(){
    ui->brush_Button->setToolTip("Brush Tool");
    ui->brushSize->setToolTip("Set Brush Size");
    ui->fill_Bucket_Button->setToolTip("Fill Bucket Tool");
    ui->eraser_Button->setToolTip("Eraser Tool");
    ui->rotate_Left_Button->setToolTip("Rotate sprite 90 degrees to the left");
    ui->rotate_Right_Button->setToolTip("Rotate sprite 90 degrees to the right");
    ui->flip_Horizontally->setToolTip("Flips the sprite across the X axis");
    ui->flip_Vertically->setToolTip("Flips the sprite across the Y axis");
    ui->zoom_In_Button->setToolTip("Zoom in");
    ui->zoom_Out_Button->setToolTip("Zoom out");
    ui->tabWidget->setTabToolTip(0, "Painting Tools");
    ui->tabWidget->setTabToolTip(1, "Transformation tools");
    ui->leftColor->setToolTip("Set color of brush");
    ui->next_frame_button->setToolTip("Next frame");
    ui->previous_frame_button->setToolTip("Previous frame");
    ui->play_button->setToolTip("Sprite Preview");
    ui->add_frame_button->setToolTip("Adds a new empty frame");
    ui->delete_Frame_Button->setToolTip("Deletes the current frame");
    ui->carryOverBox->setToolTip("If checked, the next frame added will be blank. If unchecked, the next frame added will be the same as the previous");

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
    QObject::connect(ui->carryOverBox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));
}

void MainWindow::zoomIn(){
    zoomCount+=1;
    currentScale += 2;
    QTransform trans;
    trans.scale(currentScale,currentScale);
    ui->graphicsView->setTransform(trans);
}

void MainWindow::zoomOut(){
    if(zoomCount > 1)
    {
        zoomCount-=1;
        currentScale -= 2;
        QTransform trans;
        trans.scale(currentScale,currentScale);
        ui->graphicsView->setTransform(trans);
    }

}

void MainWindow::openProj(){
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "", "Sprite Sheet Project File (*.spp)");
    if(filename != NULL)
    {
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);

            for(unsigned int i = 0; i < frames.size(); i++)
            {
                ui->framesLayout->removeWidget(frames.at(i));
            }
            frames.at(0)->clear();
            frames.clear();

            QString heightAndWidth = stream.readLine();
            QString numFrames = stream.readLine();
            QString frameString;
            frameString = stream.readAll();

            file.close();
            emit sendOpenProj(heightAndWidth, numFrames, frameString);
            ui->brushSize->setValue(1);
        }
    }
}

void MainWindow::sendSaveAsSig(){
    emit sendSaveAs();
}

void MainWindow::saveAsSelected(QString fileInfo){
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", "Sprite Sheet Project File (*.spp)");
    if(filename != NULL)
    {
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        stream << fileInfo;
        file.close();
    }
}

void MainWindow::exportToGifSig(){
    emit sendExportGif();
}

//gif writer doesn't seem to produce what we want...
void MainWindow::exportGif(std::vector<QImage> frameList){
    GifWriter *gifWriter = new GifWriter(); // leaking memory ?
    QString filename = QFileDialog::getSaveFileName(this, "Save gif", "", "Sprite Gif File (*.gif)");
    GifBegin(gifWriter,filename.toLatin1().constData(),frameList[0].width(),frameList[0].height(),5);
    QImage image;
    for(unsigned int i = 0; i < frameList.size(); i++)
    {
        image = frameList[i];
        image = image.convertToFormat(QImage::Format_RGBX8888, Qt::ThresholdDither);
        uint8_t *charAr = image.bits();
        GifWriteFrame(gifWriter,charAr,frameList[0].width(),frameList[0].height(),5,8,false);
    }
    GifEnd(gifWriter);
}

void MainWindow::openConfigurationSelected(){
     this->configuration.show();
     this->configuration.raise();
}

void MainWindow::spinnerChanged(int value){
    QSpinBox * spin = static_cast<QSpinBox*>(QObject::sender());
    Property tosend(spin->objectName());
    tosend.addValue(value);
    emit sendPropertyChange(tosend);
}

void MainWindow::checkBoxChanged(int value){
    QCheckBox * box = static_cast<QCheckBox*>(QObject::sender());
    Property tosend(box->objectName());
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

    QPainter p(image);
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem();
    QPixmap map = QPixmap::fromImage(*image);
    item->setPixmap(map);
    scene->addItem(item);

    ui->framesLayout->update();
    ui->graphicsView->update();
}

void MainWindow::updateFrames(std::vector<QImage> frameList, unsigned int currentFrame){
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
            frames.at(i)->setStyleSheet("border: 1px solid black");
        }
        imIt++;
    }
}

void MainWindow::addFrameToLayout(QImage * image){
    QLabel * frame = new QLabel();
    frame->show();
    frame->setScaledContents(true);
    frame->setMinimumSize(75,75);
    frame->setMaximumSize(75,75);
    frame->setPixmap(QPixmap::fromImage(*image));
    ui->framesLayout->addWidget(frame);
    frames.push_back(frame);
}

void MainWindow::deleteFrame(unsigned int frameToDelete){
    frames.at(frameToDelete)->setStyleSheet("border: 1px solid black");
    ui->framesLayout->removeWidget(frames[frameToDelete]);
    frames.at(frameToDelete)->clear();
    frames.erase(frames.begin()+frameToDelete);
}

bool MainWindow::eventFilter(QObject* obj, QEvent *event){
        //this will get all the input for every button
        if(event->type()==QEvent::MouseButtonPress){
            QWidget * child = childAt(static_cast<QMouseEvent *>(event)->pos());
            QLabel* label = dynamic_cast<QLabel*>(child); // type check the input
            QToolButton* button = dynamic_cast<QToolButton*>(child);
            if(label!=NULL||button!=NULL) {
                if(button!=NULL){
                    button->animateClick();
                }
                emit sendButtonInput(child);
                return false;
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


        QWidget * child = childAt(static_cast<QMouseEvent *>(event)->pos());
        QGraphicsScene * scene = dynamic_cast<QGraphicsScene*>(child); // type check the input
        if(scene!=NULL&&(event->type()==QEvent::MouseButtonPress||event->type()==QEvent::MouseMove||event->type()==QEvent::MouseButtonRelease))
        {
            return true;
        }

    return false;
}

void MainWindow::setActiveButton(unsigned int toolNum){
    switch(toolNum)
    {
        case 0:
            ui->brush_Button->setStyleSheet("background: chartreuse");
            ui->eraser_Button->setStyleSheet("background: gainsboro");
            ui->fill_Bucket_Button->setStyleSheet("background: gainsboro");
            ui->rectangle_button->setStyleSheet("background: gainsboro");
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            break;
        case 1:
            ui->brush_Button->setStyleSheet("background: gainsboro");
            ui->eraser_Button->setStyleSheet("background: chartreuse");
            ui->fill_Bucket_Button->setStyleSheet("background: gainsboro");
            ui->rectangle_button->setStyleSheet("background: gainsboro");
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            break;
        case 2:
            ui->brush_Button->setStyleSheet("background: gainsboro");
            ui->eraser_Button->setStyleSheet("background: gainsboro");
            ui->fill_Bucket_Button->setStyleSheet("background: chartreuse");
            ui->rectangle_button->setStyleSheet("background: gainsboro");
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            break;
        case 3:
            ui->brush_Button->setStyleSheet("background: gainsboro");
            ui->eraser_Button->setStyleSheet("background: gainsboro");
            ui->fill_Bucket_Button->setStyleSheet("background: gainsboro");
            ui->rectangle_button->setStyleSheet("background: chartreuse");
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            break;
        case 4:
            ui->brush_Button->setStyleSheet("background: gainsboro");
            ui->eraser_Button->setStyleSheet("background: gainsboro");
            ui->fill_Bucket_Button->setStyleSheet("background: gainsboro");
            ui->rectangle_button->setStyleSheet("background: gainsboro");
            ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
            break;
    }
}

MainWindow::~MainWindow(){
    delete boundary;
    delete ui;
    delete scene;
}


PreviewWindow * MainWindow::getPreview(){
    return &preview;
}


void MainWindow::on_play_button_pressed(){
    if(!preview.isVisible()){
        preview.show();
        //change the button icon to pause?
    }
    //else
        //call another slot which will pause the animation
}

