/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "colorbox.h"

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
    ColorBox *leftColor;
    ColorBox *leftColor_2;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(924, 580);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(200, 20, 541, 431));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(180, 20, 20, 431));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(200, 460, 541, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(740, 20, 20, 431));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        add_Frame_Button = new QToolButton(centralWidget);
        add_Frame_Button->setObjectName(QStringLiteral("add_Frame_Button"));
        add_Frame_Button->setGeometry(QRect(690, 470, 51, 41));
        previous_frame_button = new QToolButton(centralWidget);
        previous_frame_button->setObjectName(QStringLiteral("previous_frame_button"));
        previous_frame_button->setGeometry(QRect(200, 480, 51, 31));
        play_button = new QToolButton(centralWidget);
        play_button->setObjectName(QStringLiteral("play_button"));
        play_button->setGeometry(QRect(270, 470, 51, 41));
        next_frame_button = new QToolButton(centralWidget);
        next_frame_button->setObjectName(QStringLiteral("next_frame_button"));
        next_frame_button->setGeometry(QRect(340, 480, 51, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(760, 20, 151, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        brush_Button = new QToolButton(tab);
        brush_Button->setObjectName(QStringLiteral("brush_Button"));
        brush_Button->setGeometry(QRect(10, 10, 51, 41));
        fill_Bucket_Button = new QToolButton(tab);
        fill_Bucket_Button->setObjectName(QStringLiteral("fill_Bucket_Button"));
        fill_Bucket_Button->setGeometry(QRect(10, 60, 51, 41));
        eraser_Button = new QToolButton(tab);
        eraser_Button->setObjectName(QStringLiteral("eraser_Button"));
        eraser_Button->setGeometry(QRect(10, 110, 51, 41));
        rectangle_button = new QToolButton(tab);
        rectangle_button->setObjectName(QStringLiteral("rectangle_button"));
        rectangle_button->setGeometry(QRect(10, 160, 51, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        rotate_Left_Button = new QToolButton(tab_2);
        rotate_Left_Button->setObjectName(QStringLiteral("rotate_Left_Button"));
        rotate_Left_Button->setGeometry(QRect(10, 160, 51, 41));
        zoom_Out_Button = new QToolButton(tab_2);
        zoom_Out_Button->setObjectName(QStringLiteral("zoom_Out_Button"));
        zoom_Out_Button->setGeometry(QRect(10, 60, 51, 41));
        rotate_Right_Button = new QToolButton(tab_2);
        rotate_Right_Button->setObjectName(QStringLiteral("rotate_Right_Button"));
        rotate_Right_Button->setGeometry(QRect(10, 110, 51, 41));
        zoom_In_Button = new QToolButton(tab_2);
        zoom_In_Button->setObjectName(QStringLiteral("zoom_In_Button"));
        zoom_In_Button->setGeometry(QRect(10, 10, 51, 41));
        leftColor = new ColorBox(tab_2);
        leftColor->setObjectName(QStringLiteral("leftColor"));
        leftColor->setGeometry(QRect(10, 350, 61, 71));
        leftColor->setAutoFillBackground(false);
        leftColor->setStyleSheet(QStringLiteral("border: 2px solid grey"));
        leftColor_2 = new ColorBox(tab_2);
        leftColor_2->setObjectName(QStringLiteral("leftColor_2"));
        leftColor_2->setGeometry(QRect(80, 350, 61, 71));
        leftColor_2->setAutoFillBackground(false);
        leftColor_2->setStyleSheet(QStringLiteral("border: 2px solid grey"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 330, 59, 14));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        add_Frame_Button->setText(QApplication::translate("MainWindow", "...", 0));
        previous_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        play_button->setText(QApplication::translate("MainWindow", "...", 0));
        next_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        brush_Button->setText(QApplication::translate("MainWindow", "Br", 0));
        fill_Bucket_Button->setText(QApplication::translate("MainWindow", "Fill", 0));
        eraser_Button->setText(QApplication::translate("MainWindow", "Erase", 0));
        rectangle_button->setText(QApplication::translate("MainWindow", "Rect", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        rotate_Left_Button->setText(QApplication::translate("MainWindow", "RotateL", 0));
        zoom_Out_Button->setText(QApplication::translate("MainWindow", "ZOut", 0));
        rotate_Right_Button->setText(QApplication::translate("MainWindow", "RotateR", 0));
        zoom_In_Button->setText(QApplication::translate("MainWindow", "Zoom In", 0));
        leftColor->setText(QString());
        leftColor_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Left Color", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
