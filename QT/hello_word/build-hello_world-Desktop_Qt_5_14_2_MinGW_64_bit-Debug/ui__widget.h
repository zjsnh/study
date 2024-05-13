/********************************************************************************
** Form generated from reading UI file '_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__WIDGET_H
#define UI__WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__Widget
{
public:
    QLabel *label;

    void setupUi(QWidget *_Widget)
    {
        if (_Widget->objectName().isEmpty())
            _Widget->setObjectName(QString::fromUtf8("_Widget"));
        _Widget->resize(800, 600);
        label = new QLabel(_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 130, 111, 51));

        retranslateUi(_Widget);

        QMetaObject::connectSlotsByName(_Widget);
    } // setupUi

    void retranslateUi(QWidget *_Widget)
    {
        _Widget->setWindowTitle(QCoreApplication::translate("_Widget", "_Widget", nullptr));
        label->setText(QCoreApplication::translate("_Widget", "hello_world", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _Widget: public Ui__Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__WIDGET_H
