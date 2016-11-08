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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCanvasSize_2;
    QAction *actionSave_as;
    QAction *actionOpen_project;
    QAction *actionExportToGif;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QGroupBox *framesBox;
    QToolButton *delete_Frame_Button;
    QToolButton *previous_frame_button;
    QToolButton *play_button;
    QToolButton *next_frame_button;
    QToolButton *add_frame_button;
    QFrame *line_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *framesLayout;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *brush_Button;
    QToolButton *fill_Bucket_Button;
    QToolButton *eraser_Button;
    QToolButton *rectangle_button;
    QSpinBox *brushSize;
    ColorBox *leftColor;
    QLabel *label;
    QWidget *tab_2;
    QToolButton *rotate_Left_Button;
    QToolButton *zoom_Out_Button;
    QToolButton *rotate_Right_Button;
    QToolButton *zoom_In_Button;
    QToolButton *flip_Horizontally;
    QToolButton *flip_Vertically;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *undo_button;
    QSpacerItem *horizontalSpacer;
    QToolButton *redo_button;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *carryOverBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(713, 624);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionCanvasSize_2 = new QAction(MainWindow);
        actionCanvasSize_2->setObjectName(QStringLiteral("actionCanvasSize_2"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionOpen_project = new QAction(MainWindow);
        actionOpen_project->setObjectName(QStringLiteral("actionOpen_project"));
        actionExportToGif = new QAction(MainWindow);
        actionExportToGif->setObjectName(QStringLiteral("actionExportToGif"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(89);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        framesBox = new QGroupBox(centralWidget);
        framesBox->setObjectName(QStringLiteral("framesBox"));
        sizePolicy.setHeightForWidth(framesBox->sizePolicy().hasHeightForWidth());
        framesBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(framesBox);

        delete_Frame_Button = new QToolButton(centralWidget);
        delete_Frame_Button->setObjectName(QStringLiteral("delete_Frame_Button"));
        delete_Frame_Button->setMinimumSize(QSize(90, 25));

        horizontalLayout->addWidget(delete_Frame_Button);

        previous_frame_button = new QToolButton(centralWidget);
        previous_frame_button->setObjectName(QStringLiteral("previous_frame_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(previous_frame_button->sizePolicy().hasHeightForWidth());
        previous_frame_button->setSizePolicy(sizePolicy2);
        previous_frame_button->setMinimumSize(QSize(90, 30));

        horizontalLayout->addWidget(previous_frame_button);

        play_button = new QToolButton(centralWidget);
        play_button->setObjectName(QStringLiteral("play_button"));
        sizePolicy2.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy2);
        play_button->setMinimumSize(QSize(90, 40));

        horizontalLayout->addWidget(play_button);

        next_frame_button = new QToolButton(centralWidget);
        next_frame_button->setObjectName(QStringLiteral("next_frame_button"));
        sizePolicy2.setHeightForWidth(next_frame_button->sizePolicy().hasHeightForWidth());
        next_frame_button->setSizePolicy(sizePolicy2);
        next_frame_button->setMinimumSize(QSize(90, 30));

        horizontalLayout->addWidget(next_frame_button);

        add_frame_button = new QToolButton(centralWidget);
        add_frame_button->setObjectName(QStringLiteral("add_frame_button"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(90);
        sizePolicy3.setVerticalStretch(20);
        sizePolicy3.setHeightForWidth(add_frame_button->sizePolicy().hasHeightForWidth());
        add_frame_button->setSizePolicy(sizePolicy3);
        add_frame_button->setMinimumSize(QSize(90, 25));

        horizontalLayout->addWidget(add_frame_button);


        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 480, 68));
        horizontalLayoutWidget = new QWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 551, 61));
        framesLayout = new QHBoxLayout(horizontalLayoutWidget);
        framesLayout->setSpacing(6);
        framesLayout->setContentsMargins(11, 11, 11, 11);
        framesLayout->setObjectName(QStringLiteral("framesLayout"));
        framesLayout->setSizeConstraint(QLayout::SetFixedSize);
        framesLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(120, 300));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        brush_Button = new QToolButton(tab);
        brush_Button->setObjectName(QStringLiteral("brush_Button"));
        brush_Button->setGeometry(QRect(10, 10, 31, 31));
        sizePolicy.setHeightForWidth(brush_Button->sizePolicy().hasHeightForWidth());
        brush_Button->setSizePolicy(sizePolicy);
        brush_Button->setPopupMode(QToolButton::InstantPopup);
        fill_Bucket_Button = new QToolButton(tab);
        fill_Bucket_Button->setObjectName(QStringLiteral("fill_Bucket_Button"));
        fill_Bucket_Button->setGeometry(QRect(50, 10, 31, 31));
        sizePolicy.setHeightForWidth(fill_Bucket_Button->sizePolicy().hasHeightForWidth());
        fill_Bucket_Button->setSizePolicy(sizePolicy);
        fill_Bucket_Button->setPopupMode(QToolButton::InstantPopup);
        eraser_Button = new QToolButton(tab);
        eraser_Button->setObjectName(QStringLiteral("eraser_Button"));
        eraser_Button->setGeometry(QRect(10, 50, 31, 31));
        eraser_Button->setPopupMode(QToolButton::InstantPopup);
        rectangle_button = new QToolButton(tab);
        rectangle_button->setObjectName(QStringLiteral("rectangle_button"));
        rectangle_button->setGeometry(QRect(50, 50, 31, 31));
        sizePolicy.setHeightForWidth(rectangle_button->sizePolicy().hasHeightForWidth());
        rectangle_button->setSizePolicy(sizePolicy);
        rectangle_button->setPopupMode(QToolButton::InstantPopup);
        brushSize = new QSpinBox(tab);
        brushSize->setObjectName(QStringLiteral("brushSize"));
        brushSize->setGeometry(QRect(10, 210, 61, 31));
        brushSize->setMinimum(1);
        brushSize->setMaximum(10);
        leftColor = new ColorBox(tab);
        leftColor->setObjectName(QStringLiteral("leftColor"));
        leftColor->setGeometry(QRect(10, 160, 41, 41));
        sizePolicy.setHeightForWidth(leftColor->sizePolicy().hasHeightForWidth());
        leftColor->setSizePolicy(sizePolicy);
        leftColor->setAutoFillBackground(false);
        leftColor->setStyleSheet(QStringLiteral("border: 2px solid grey"));
        leftColor->setLineWidth(1);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 140, 71, 16));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        rotate_Left_Button = new QToolButton(tab_2);
        rotate_Left_Button->setObjectName(QStringLiteral("rotate_Left_Button"));
        rotate_Left_Button->setGeometry(QRect(50, 50, 31, 31));
        sizePolicy.setHeightForWidth(rotate_Left_Button->sizePolicy().hasHeightForWidth());
        rotate_Left_Button->setSizePolicy(sizePolicy);
        zoom_Out_Button = new QToolButton(tab_2);
        zoom_Out_Button->setObjectName(QStringLiteral("zoom_Out_Button"));
        zoom_Out_Button->setGeometry(QRect(50, 10, 31, 31));
        sizePolicy.setHeightForWidth(zoom_Out_Button->sizePolicy().hasHeightForWidth());
        zoom_Out_Button->setSizePolicy(sizePolicy);
        rotate_Right_Button = new QToolButton(tab_2);
        rotate_Right_Button->setObjectName(QStringLiteral("rotate_Right_Button"));
        rotate_Right_Button->setGeometry(QRect(10, 50, 31, 31));
        sizePolicy.setHeightForWidth(rotate_Right_Button->sizePolicy().hasHeightForWidth());
        rotate_Right_Button->setSizePolicy(sizePolicy);
        rotate_Right_Button->setStyleSheet(QLatin1String("QToolButton{\n"
"	-moz-box-shadow:inset 38px -12px 48px -15px #0a1211;\n"
"	-webkit-box-shadow:inset 38px -12px 48px -15px #0a1211;\n"
"	box-shadow:inset 38px -12px 48px -15px #0a1211;\n"
"	background:-webkit-gradient(linear, left top, left bottom, color-stop(0.05, #25b891), color-stop(1, #6c7c7c));\n"
"	background:-moz-linear-gradient(top, #25b891 5%, #6c7c7c 100%);\n"
"	background:-webkit-linear-gradient(top, #25b891 5%, #6c7c7c 100%);\n"
"	background:-o-linear-gradient(top, #25b891 5%, #6c7c7c 100%);\n"
"	background:-ms-linear-gradient(top, #25b891 5%, #6c7c7c 100%);\n"
"	background:linear-gradient(to bottom, #25b891 5%, #6c7c7c 100%);\n"
"	filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#25b891', endColorstr='#6c7c7c',GradientType=0);\n"
"	background-color:#25b891;\n"
"	-moz-border-radius:5px;\n"
"	-webkit-border-radius:5px;\n"
"	border-radius:5px;\n"
"	border:1px solid #566963;\n"
"	display:inline-block;\n"
"	cursor:pointer;\n"
"	color:#ffccff;\n"
"	font-family:Arial;\n"
"	font-size:15px;"
                        "\n"
"	font-weight:bold;\n"
"	padding:14px 9px;\n"
"	text-decoration:none;\n"
"	text-shadow:3px 3px 10px #039c85;\n"
"}"));
        zoom_In_Button = new QToolButton(tab_2);
        zoom_In_Button->setObjectName(QStringLiteral("zoom_In_Button"));
        zoom_In_Button->setGeometry(QRect(10, 10, 31, 31));
        sizePolicy.setHeightForWidth(zoom_In_Button->sizePolicy().hasHeightForWidth());
        zoom_In_Button->setSizePolicy(sizePolicy);
        zoom_In_Button->setAutoFillBackground(false);
        flip_Horizontally = new QToolButton(tab_2);
        flip_Horizontally->setObjectName(QStringLiteral("flip_Horizontally"));
        flip_Horizontally->setGeometry(QRect(10, 90, 31, 31));
        sizePolicy.setHeightForWidth(flip_Horizontally->sizePolicy().hasHeightForWidth());
        flip_Horizontally->setSizePolicy(sizePolicy);
        flip_Horizontally->setAutoFillBackground(false);
        flip_Vertically = new QToolButton(tab_2);
        flip_Vertically->setObjectName(QStringLiteral("flip_Vertically"));
        flip_Vertically->setGeometry(QRect(50, 90, 31, 31));
        sizePolicy.setHeightForWidth(flip_Vertically->sizePolicy().hasHeightForWidth());
        flip_Vertically->setSizePolicy(sizePolicy);
        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        undo_button = new QToolButton(centralWidget);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        sizePolicy2.setHeightForWidth(undo_button->sizePolicy().hasHeightForWidth());
        undo_button->setSizePolicy(sizePolicy2);
        undo_button->setMinimumSize(QSize(70, 70));
        undo_button->setMaximumSize(QSize(70, 70));
        undo_button->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(undo_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        redo_button = new QToolButton(centralWidget);
        redo_button->setObjectName(QStringLiteral("redo_button"));
        sizePolicy2.setHeightForWidth(redo_button->sizePolicy().hasHeightForWidth());
        redo_button->setSizePolicy(sizePolicy2);
        redo_button->setMinimumSize(QSize(70, 70));
        redo_button->setMaximumSize(QSize(70, 70));
        redo_button->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(redo_button);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        carryOverBox = new QCheckBox(centralWidget);
        carryOverBox->setObjectName(QStringLiteral("carryOverBox"));
        carryOverBox->setEnabled(true);
        carryOverBox->setChecked(true);

        verticalLayout_2->addWidget(carryOverBox);


        horizontalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionCanvasSize_2);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionOpen_project);
        menuFile->addAction(actionExportToGif);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sprite Editor eXtreme", 0));
        actionCanvasSize_2->setText(QApplication::translate("MainWindow", "Configuration", 0));
#ifndef QT_NO_TOOLTIP
        actionCanvasSize_2->setToolTip(QApplication::translate("MainWindow", "Open configuration page", 0));
#endif // QT_NO_TOOLTIP
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionOpen_project->setText(QApplication::translate("MainWindow", "Open project...", 0));
        actionExportToGif->setText(QApplication::translate("MainWindow", "Export to Gif", 0));
        framesBox->setTitle(QApplication::translate("MainWindow", "Frames", 0));
        delete_Frame_Button->setText(QApplication::translate("MainWindow", "Delete Frame", 0));
        previous_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        play_button->setText(QApplication::translate("MainWindow", "...", 0));
        next_frame_button->setText(QApplication::translate("MainWindow", "...", 0));
        add_frame_button->setText(QApplication::translate("MainWindow", "Add Frame", 0));
        brush_Button->setText(QString());
        fill_Bucket_Button->setText(QString());
        eraser_Button->setText(QString());
        rectangle_button->setText(QString());
        leftColor->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Left Color", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        rotate_Left_Button->setText(QString());
        zoom_Out_Button->setText(QString());
        rotate_Right_Button->setText(QString());
        zoom_In_Button->setText(QString());
        flip_Horizontally->setText(QString());
        flip_Vertically->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
        label_2->setText(QApplication::translate("MainWindow", "Undo/Redo", 0));
        undo_button->setText(QString());
        redo_button->setText(QString());
        carryOverBox->setText(QApplication::translate("MainWindow", "Blank Frame", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
