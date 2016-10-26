/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QToolButton *add_Frame_Button;
    QToolButton *previous_frame_button;
    QToolButton *play_button;
    QToolButton *next_frame_button;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *brush_Button;
    QToolButton *fill_Bucket_Button;
    QToolButton *eraser_Button;
    QToolButton *rectangle_button;
    QWidget *tab_2;
    QToolButton *rotate_Left_Button;
    QToolButton *zoom_Out_Button;
    QToolButton *rotate_Right_Button;
    QToolButton *zoom_In_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(924, 580);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(200, 20, 541, 431));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(180, 20, 20, 431));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(200, 460, 541, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(740, 20, 20, 431));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        add_Frame_Button = new QToolButton(centralWidget);
        add_Frame_Button->setObjectName(QString::fromUtf8("add_Frame_Button"));
        add_Frame_Button->setGeometry(QRect(690, 470, 51, 41));
        previous_frame_button = new QToolButton(centralWidget);
        previous_frame_button->setObjectName(QString::fromUtf8("previous_frame_button"));
        previous_frame_button->setGeometry(QRect(200, 480, 51, 31));
        play_button = new QToolButton(centralWidget);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setGeometry(QRect(270, 470, 51, 41));
        next_frame_button = new QToolButton(centralWidget);
        next_frame_button->setObjectName(QString::fromUtf8("next_frame_button"));
        next_frame_button->setGeometry(QRect(340, 480, 51, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(760, 20, 151, 461));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        brush_Button = new QToolButton(tab);
        brush_Button->setObjectName(QString::fromUtf8("brush_Button"));
        brush_Button->setGeometry(QRect(10, 10, 51, 41));
        fill_Bucket_Button = new QToolButton(tab);
        fill_Bucket_Button->setObjectName(QString::fromUtf8("fill_Bucket_Button"));
        fill_Bucket_Button->setGeometry(QRect(10, 60, 51, 41));
        eraser_Button = new QToolButton(tab);
        eraser_Button->setObjectName(QString::fromUtf8("eraser_Button"));
        eraser_Button->setGeometry(QRect(10, 110, 51, 41));
        rectangle_button = new QToolButton(tab);
        rectangle_button->setObjectName(QString::fromUtf8("rectangle_button"));
        rectangle_button->setGeometry(QRect(10, 160, 51, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        rotate_Left_Button = new QToolButton(tab_2);
        rotate_Left_Button->setObjectName(QString::fromUtf8("rotate_Left_Button"));
        rotate_Left_Button->setGeometry(QRect(10, 160, 51, 41));
        zoom_Out_Button = new QToolButton(tab_2);
        zoom_Out_Button->setObjectName(QString::fromUtf8("zoom_Out_Button"));
        zoom_Out_Button->setGeometry(QRect(10, 60, 51, 41));
        rotate_Right_Button = new QToolButton(tab_2);
        rotate_Right_Button->setObjectName(QString::fromUtf8("rotate_Right_Button"));
        rotate_Right_Button->setGeometry(QRect(10, 110, 51, 41));
        zoom_In_Button = new QToolButton(tab_2);
        zoom_In_Button->setObjectName(QString::fromUtf8("zoom_In_Button"));
        zoom_In_Button->setGeometry(QRect(10, 10, 51, 41));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        add_Frame_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        previous_frame_button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        play_button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        next_frame_button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        brush_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        fill_Bucket_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        eraser_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        rectangle_button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        rotate_Left_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        zoom_Out_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        rotate_Right_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        zoom_In_Button->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
