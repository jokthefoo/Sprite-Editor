#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPalette>
#include <QGraphicsRectItem>
#include <QImage>
#include <QInputDialog>
#include <QLineEdit>
#include <QAction>
#include <QToolButton>
#include <grid.h>
#include <iostream>
#include <configurationform.h>
#include <property.h>
#include <previewwindow.h>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateEditor(QImage * image);
    PreviewWindow * getPreview();
    ~MainWindow();

signals:
    void sendMouseInput(QPointF, QMouseEvent*);
    void sendButtonInput(QWidget*);
    void sendPropertyChange(Property);
    void sendSaveAs();
    void sendOpenProj(QString,QString,QString);


public slots:
    void scaleView(int);
    void saveAsSelected(QString);
    void sendConfigurationInput();
    void openConfigurationSelected();
    void spinnerChanged(int);
    void updateScreen(QImage * toShow);
    void updateColor(QColor); // left is false right is true

    // void updatePreview(std::vector<Grid>);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_play_button_pressed();
    void sendSaveAsSig();
    void openProj();

private:
    ConfigurationForm configuration;
    PreviewWindow preview;
    void connectComponents();
    void setupIcons();
    void setupToolTips();
    QGraphicsRectItem * boundary; // should move this to the model
    Ui::MainWindow * ui;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
