/********************************************************************************
** Form generated from reading UI file 'configurationform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONFORM_H
#define UI_CONFIGURATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationForm
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLineEdit *canvasHeightEdit;
    QLineEdit *canvasWidthEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;

    void setupUi(QDialog *ConfigurationForm)
    {
        if (ConfigurationForm->objectName().isEmpty())
            ConfigurationForm->setObjectName(QStringLiteral("ConfigurationForm"));
        ConfigurationForm->resize(400, 300);
        buttonBox = new QDialogButtonBox(ConfigurationForm);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(110, 260, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(ConfigurationForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 181, 251));
        canvasHeightEdit = new QLineEdit(groupBox);
        canvasHeightEdit->setObjectName(QStringLiteral("canvasHeightEdit"));
        canvasHeightEdit->setGeometry(QRect(40, 20, 41, 22));
        canvasWidthEdit = new QLineEdit(groupBox);
        canvasWidthEdit->setObjectName(QStringLiteral("canvasWidthEdit"));
        canvasWidthEdit->setGeometry(QRect(110, 20, 41, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 20, 16, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 20, 16, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 31, 20));

        retranslateUi(ConfigurationForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigurationForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigurationForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigurationForm);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationForm)
    {
        ConfigurationForm->setWindowTitle(QApplication::translate("ConfigurationForm", "Project Configuration", 0));
        groupBox->setTitle(QApplication::translate("ConfigurationForm", "Sprite Settings", 0));
        label_4->setText(QApplication::translate("ConfigurationForm", "Px", 0));
        label_5->setText(QApplication::translate("ConfigurationForm", "Px", 0));
        label->setText(QApplication::translate("ConfigurationForm", "Size", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationForm: public Ui_ConfigurationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONFORM_H
