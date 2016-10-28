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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

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
    QPushButton *newSprite;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1130, 750);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setGeometry(QRect(200, 20, 505, 505));
        graphicsView->setAutoFillBackground(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(170, 20, 20, 541));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(200, 580, 551, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(760, 20, 20, 541));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        add_Frame_Button = new QToolButton(centralWidget);
        add_Frame_Button->setObjectName(QStringLiteral("add_Frame_Button"));
        add_Frame_Button->setGeometry(QRect(700, 620, 51, 41));
        previous_frame_button = new QToolButton(centralWidget);
        previous_frame_button->setObjectName(QStringLiteral("previous_frame_button"));
        previous_frame_button->setGeometry(QRect(200, 630, 51, 31));
        play_button = new QToolButton(centralWidget);
        play_button->setObjectName(QStringLiteral("play_button"));
        play_button->setGeometry(QRect(260, 620, 51, 41));
        next_frame_button = new QToolButton(centralWidget);
        next_frame_button->setObjectName(QStringLiteral("next_frame_button"));
        next_frame_button->setGeometry(QRect(320, 630, 51, 31));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(890, 20, 131, 461));
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
        tabWidget->addTab(tab_2, QString());
        newSprite = new QPushButton(centralWidget);
        newSprite->setObjectName(QStringLiteral("newSprite"));
        newSprite->setGeometry(QRect(20, 510, 111, 91));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1130, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        add_Frame_Button->setText(QApplication::translate("MainWindow", "...", 0));
        previous_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        play_button->setText(QApplication::translate("MainWindow", "...", 0));
        next_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        brush_Button->setText(QApplication::translate("MainWindow", "...", 0));
        fill_Bucket_Button->setText(QApplication::translate("MainWindow", "...", 0));
        eraser_Button->setText(QApplication::translate("MainWindow", "...", 0));
        rectangle_button->setText(QApplication::translate("MainWindow", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        rotate_Left_Button->setText(QApplication::translate("MainWindow", "...", 0));
        zoom_Out_Button->setText(QApplication::translate("MainWindow", "...", 0));
        rotate_Right_Button->setText(QApplication::translate("MainWindow", "...", 0));
        zoom_In_Button->setText(QApplication::translate("MainWindow", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
        newSprite->setText(QApplication::translate("MainWindow", "New", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
