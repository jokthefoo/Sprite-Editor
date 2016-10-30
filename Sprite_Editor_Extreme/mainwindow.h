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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void updateEditor(QImage * image);
    ~MainWindow();

signals:
    void sendMouseInput(QPointF, QMouseEvent*);
    void sendButtonInput(QWidget*);
    void sendPropertyChange(Property);


public slots:
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

private:
    ConfigurationForm configuration;
    PreviewWindow *preview;
    void connectComponents();
    void setupIcons();
    QGraphicsRectItem * boundary; // should move this to the model
    Ui::MainWindow * ui;
    QGraphicsScene * scene;

};

#endif // MAINWINDOW_H
