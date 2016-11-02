/********************************************************************************
** Form generated from reading UI file 'previewwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWWINDOW_H
#define UI_PREVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PreviewWindow)
    {
        if (PreviewWindow->objectName().isEmpty())
            PreviewWindow->setObjectName(QStringLiteral("PreviewWindow"));
        PreviewWindow->resize(800, 600);
        centralwidget = new QWidget(PreviewWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(5, 1, 791, 571));
        PreviewWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PreviewWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        PreviewWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PreviewWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PreviewWindow->setStatusBar(statusbar);

        retranslateUi(PreviewWindow);

        QMetaObject::connectSlotsByName(PreviewWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PreviewWindow)
    {
        PreviewWindow->setWindowTitle(QApplication::translate("PreviewWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class PreviewWindow: public Ui_PreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWWINDOW_H
