/********************************************************************************
** Form generated from reading UI file 'createnew.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEW_H
#define UI_CREATENEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_createNew
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *sizeSlider;
    QLabel *label_2;
    QLCDNumber *size;
    QLCDNumber *size_2;

    void setupUi(QDialog *createNew)
    {
        if (createNew->objectName().isEmpty())
            createNew->setObjectName(QStringLiteral("createNew"));
        createNew->setEnabled(true);
        createNew->resize(271, 211);
        createNew->setContextMenuPolicy(Qt::DefaultContextMenu);
        buttonBox = new QDialogButtonBox(createNew);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 140, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(createNew);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 261, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        sizeSlider = new QSlider(createNew);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        sizeSlider->setEnabled(true);
        sizeSlider->setGeometry(QRect(10, 50, 241, 22));
        sizeSlider->setMinimum(2);
        sizeSlider->setMaximum(100);
        sizeSlider->setSingleStep(2);
        sizeSlider->setPageStep(2);
        sizeSlider->setTracking(false);
        sizeSlider->setOrientation(Qt::Horizontal);
        sizeSlider->setTickPosition(QSlider::NoTicks);
        sizeSlider->setTickInterval(2);
        label_2 = new QLabel(createNew);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 80, 21, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        size = new QLCDNumber(createNew);
        size->setObjectName(QStringLiteral("size"));
        size->setGeometry(QRect(140, 80, 81, 41));
        size->setLayoutDirection(Qt::LeftToRight);
        size->setDigitCount(3);
        size->setProperty("intValue", QVariant(2));
        size_2 = new QLCDNumber(createNew);
        size_2->setObjectName(QStringLiteral("size_2"));
        size_2->setGeometry(QRect(10, 80, 91, 41));
        size_2->setDigitCount(3);
        size_2->setProperty("intValue", QVariant(2));

        retranslateUi(createNew);
        QObject::connect(sizeSlider, SIGNAL(valueChanged(int)), size_2, SLOT(display(int)));
        QObject::connect(sizeSlider, SIGNAL(valueChanged(int)), size, SLOT(display(int)));
        QObject::connect(buttonBox, SIGNAL(rejected()), createNew, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), createNew, SLOT(accept()));

        QMetaObject::connectSlotsByName(createNew);
    } // setupUi

    void retranslateUi(QDialog *createNew)
    {
        createNew->setWindowTitle(QApplication::translate("createNew", "Dialog", 0));
        label->setText(QApplication::translate("createNew", "ENTER THE SIZE OF SPRITE", 0));
        label_2->setText(QApplication::translate("createNew", "X", 0));
    } // retranslateUi

};

namespace Ui {
    class createNew: public Ui_createNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEW_H
