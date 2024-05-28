/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton_male;
    QRadioButton *radioButton_female;
    QLabel *label_4;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_phone;
    QLabel *label_5;
    QPushButton *pushButton;
    QLineEdit *lineEdit_password_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(9);
        Widget->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 180, 81, 18));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 230, 81, 18));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 390, 81, 18));
        radioButton_male = new QRadioButton(Widget);
        radioButton_male->setObjectName(QString::fromUtf8("radioButton_male"));
        radioButton_male->setGeometry(QRect(310, 350, 132, 22));
        radioButton_female = new QRadioButton(Widget);
        radioButton_female->setObjectName(QString::fromUtf8("radioButton_female"));
        radioButton_female->setGeometry(QRect(410, 350, 132, 22));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 340, 81, 18));
        lineEdit_account = new QLineEdit(Widget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(280, 180, 191, 25));
        lineEdit_password = new QLineEdit(Widget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(280, 240, 191, 25));
        lineEdit_phone = new QLineEdit(Widget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(280, 390, 191, 25));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 100, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setFrameShape(QFrame::NoFrame);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 480, 112, 34));
        lineEdit_password_2 = new QLineEdit(Widget);
        lineEdit_password_2->setObjectName(QString::fromUtf8("lineEdit_password_2"));
        lineEdit_password_2->setGeometry(QRect(280, 290, 191, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\224\265\350\257\235\357\274\232", nullptr));
        radioButton_male->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        radioButton_female->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
