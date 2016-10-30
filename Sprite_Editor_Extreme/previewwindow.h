#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QMainWindow>

namespace Ui {
class PreviewWindow;
}

class PreviewWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PreviewWindow(QWidget *parent = 0);
    Ui::PreviewWindow * get();
    ~PreviewWindow();

private:
    Ui::PreviewWindow *ui;
};

#endif // PREVIEWWINDOW_H
