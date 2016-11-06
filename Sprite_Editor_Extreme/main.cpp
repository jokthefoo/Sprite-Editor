#include "mainwindow.h"
#include <QApplication>
#include <controller.h>
#include <QPlatformSurfaceEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    a.setStyle("plastique");
    Controller controller(&w);
    w.show();
    return a.exec();
}
