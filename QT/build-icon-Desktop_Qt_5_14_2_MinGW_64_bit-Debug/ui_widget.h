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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        pushButton_up = new QPushButton(Widget);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(130, 390, 112, 34));
        pushButton_down = new QPushButton(Widget);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(280, 390, 112, 34));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(150, 370, 81, 18));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 200, 41, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 230, 41, 16));
        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(210, 90, 344, 248));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_up->setText(QCoreApplication::translate("Widget", "up", nullptr));
        pushButton_down->setText(QCoreApplication::translate("Widget", "down", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\224\250\346\210\267\351\241\273\347\237\245", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
