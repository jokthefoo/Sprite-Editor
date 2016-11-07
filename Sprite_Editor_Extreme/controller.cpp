#include "controller.h"

Controller::Controller(MainWindow * w)
{
    model = new Model;

    //connect everything
    QObject::connect(w, &MainWindow::sendMouseInput, this, &Controller::receiveMouseInput);
    QObject::connect(w, &MainWindow::sendButtonInput, this, &Controller::receiveButtonInput);
    QObject::connect(w, &MainWindow::sendPropertyChange, this, &Controller::receivePropertyChange);
    QObject::connect(w, &MainWindow::sendSaveAs, this, &Controller::receiveSaveAs);
    QObject::connect(w, &MainWindow::sendExportGif, this, &Controller::receiveExport);
    QObject::connect(w, &MainWindow::sendOpenProj, this, &Controller::receiveOpenProj);
    QObject::connect(this, &Controller::sendImage, w, &MainWindow::updateScreen);
    QObject::connect(this, &Controller::sendFrames, w, &MainWindow::updateFrames);
    QObject::connect(this, &Controller::sendFramesForExport, w, &MainWindow::exportGif);
    QObject::connect(this, &Controller::sendNewFrame, w, &MainWindow::addFrameToLayout);
    QObject::connect(this, &Controller::saveAs, w, &MainWindow::saveAsSelected);
    QObject::connect(this, &Controller::sendColor, w, &MainWindow::updateColor);
    QObject::connect(this, &Controller::sendPreviewImage, w->getPreview(), &PreviewWindow::updatePreview);
    QObject::connect(this, &Controller::sendActiveTool, w, &MainWindow::setActiveButton);
    QObject::connect(&timer, &QTimer::timeout, this, &Controller::timeoutSendImage);
    QObject::connect(this, &Controller::sendDeleteFrame, w, &MainWindow::deleteFrame);


    //send the initial state the to the view
    emit sendImage(model->getProject()->getCurrentFrame()->getImage());
    emit sendNewFrame(model->getProject()->getCurrentFrame()->getImage());
    emit sendColor(model->getColor());
    emit sendActiveTool(0);
}

Controller::~Controller(){
    delete model;
}

void Controller::receiveExport()
{
    std::vector<QImage> frames;
    std::vector<Grid*> temp = model->getProject()->getAllFrames();
    for(std::vector<Grid*>::iterator it = temp.begin(); it != temp.end(); ++it)
    {
        Grid * g = *it;
        frames.push_back(*(g->getImage()));
    }
    emit sendFramesForExport(frames);
}

void Controller::receiveOpenProj(QString heightWidth, QString numFrames, QString frames)
{
    QStringList list;
    list = heightWidth.split(QRegularExpression("\\s+"));
    int h = list.takeFirst().toInt();
    int w = list.takeLast().toInt();
    model = new Model;
    int parse = numFrames.toInt();
    QStringList frameList;

    frameList = frames.split(QRegularExpression("Frame: \\d+\\n"));
    if(frameList.first() == "")
    {
        frameList.removeFirst();
    }

    QStringList::iterator listIt = frameList.begin();
    for(int i = 0; i < parse; i++){
        Grid * grid = new Grid(h,w);
        grid->fromString(*listIt);
        listIt++;
        model->getProject()->addNewFrame(grid);
        emit sendNewFrame(grid->getImage());
    }
    model->getProject()->removeFrame(0);
    model->getProject()->changeFrame(0);
    emit sendImage(model->getProject()->getCurrentFrame()->getImage());
    emit sendColor(model->getColor());
    emit sendActiveTool(0);
    sendAllFrame();
}

void Controller::sendAllFrame()
{
    std::vector<QImage> frames;
    std::vector<Grid*> temp = model->getProject()->getAllFrames();
    for(std::vector<Grid*>::iterator it = temp.begin(); it != temp.end(); ++it)
    {
        Grid * g = *it;
        frames.push_back(*(g->getImage()));
    }
    emit sendFrames(frames, model->getProject()->getWorkingFrame());
}

void Controller::receiveSaveAs()
{
    emit saveAs(model->getProject()->toString());
}

void Controller::receivePropertyChange(Property p){
    if(p.values.size()>0){
        if(p.name.toStdString().compare("brushSize")==0){
            if(p.values.front()>0){
                model->setBrushSize(p.values.front());
            }
        }
        if(p.name.toStdString().compare("canvasSize")==0){
            model->getProject()->setCanvasSize(p.values[0],p.values[1]);
            emit sendImage(model->getProject()->getCurrentFrame()->getImage());
            sendAllFrame();
        }
        if (p.name.toStdString().compare("carryOverBox") == 0) {
            if (p.values.front() == 0) {
                addBlankFrame = false;
            } else if (p.values.front() == 2) {
                addBlankFrame = true;
            }
        }
    }
}

void Controller::receiveMouseInput(QPointF point, QMouseEvent *event)
{
    if (allowDrawing)
    {
      Grid * currentFrame = model->getProject()->getCurrentFrame();
        if(model->getCurrentTool()!=nullptr){
            Tool * tool = model->getCurrentTool();
            tool->applyTool(currentFrame,point, event,model->getColor(),model->getBrushSize(), model->getProject());
            emit sendImage(model->getProject()->getCurrentFrame()->getImage());
            sendAllFrame();
        }

    }
}

// decode buttons here
void Controller::receiveButtonInput(QWidget * child)
{

    QLabel * label = dynamic_cast<QLabel*>(child); // type check the input
    if(label!=NULL){
        QString str = label->objectName();
        int x =  QString::compare(str, "leftColor", Qt::CaseInsensitive);
        if(x == 0){
            allowDrawing = false;
            QColor c = QColorDialog::getColor(Qt::white);
            allowDrawing = true;
            if (c.isValid())
            {
                model->setColor(c);
                emit sendColor(model->getColor());
            }
        }
        return;
    }


    QToolButton * button = dynamic_cast<QToolButton*>(child);
    if(button!=NULL){// there's a generic way to do this
        decodeAction(button->objectName());
    }
}

int animation_counter = 0;
void Controller::timeoutSendImage(){
    std::vector<Grid*> g = model->getProject()->getAllFrames();
    // might want to send a pointer of the frames so we aren't copying the vector every time.

    int size = g.size();
    if(animation_counter < size){
        emit sendPreviewImage(&(*g[animation_counter]->getImage()));
        animation_counter++;
    }else{
        animation_counter = 0;
    }
}


//decode buttons here:
void Controller::decodeAction(QString n){
    std::string name = n.toStdString();
    if(name == "rotate_Right_Button")
    {
        model->getProject()->addEdit();
        model->rotateImage(90);
    }
    else if(name  == "rotate_Left_Button")
    {
        model->getProject()->addEdit();
        model->rotateImage(-90);
    }
    else if(name  == "flip_Horizontally")
    {
        model->getProject()->addEdit();
        model->getProject()->getCurrentFrame()->flipImage("hor");
    }
    else if(name  == "flip_Vertically")
    {
        model->getProject()->addEdit();
        model->getProject()->getCurrentFrame()->flipImage("vert");
    }
    else if(name == "brush_Button")
    {
        model->changeTool(0);
        emit sendActiveTool(0);
    }
    else if (name == "eraser_Button")
    {
        model->changeTool(1);
        emit sendActiveTool(1);
    }
    else if (name == "fill_Bucket_Button")
    {
        model->changeTool(2);
        emit sendActiveTool(2);
    }
    else if (name == "rectangle_button")
    {
        model->changeTool(3);
        emit sendActiveTool(3);
    }
    else if( name == "play_button"){
        timer.start(100);
    }
    else if( name == "next_frame_button")
    {
        model->getProject()->next();
    }
    else if( name == "previous_frame_button")
    {
        model->getProject()->previous();
    }
    else if(name == "add_frame_button")
    {
        if (addBlankFrame) {
            model->getProject()->addEmptyFrame();
        } else {
            model->getProject()->carryOverNewFrame(*(model->getProject()->getCurrentFrame()));
        }
        emit sendNewFrame(model->getProject()->getCurrentFrame()->getImage());
    }
    else if(name == "delete_Frame_Button")
    {
        if(model->getProject()->getAllFrames().size() > 1)
        {
            emit sendDeleteFrame(model->getProject()->getWorkingFrame());
            model->getProject()->deleteCurrentFrame();
        }
    }else if(name == "undo_button"){
        model->getProject()->undo();

    }else if(name == "redo_button"){
        model->getProject()->redo();
    }
    emit sendImage(model->getProject()->getCurrentFrame()->getImage());
    sendAllFrame();
    return;
}







