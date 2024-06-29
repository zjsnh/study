/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *pushButton;
    QPushButton *playerVsPlayerButton;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(800, 600);
        pushButton = new QPushButton(StartWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 200, 271, 101));
        playerVsPlayerButton = new QPushButton(StartWindow);
        playerVsPlayerButton->setObjectName(QString::fromUtf8("playerVsPlayerButton"));
        playerVsPlayerButton->setGeometry(QRect(220, 390, 281, 81));

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("StartWindow", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        playerVsPlayerButton->setText(QCoreApplication::translate("StartWindow", "\347\216\251\345\256\266\345\257\271\346\210\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
