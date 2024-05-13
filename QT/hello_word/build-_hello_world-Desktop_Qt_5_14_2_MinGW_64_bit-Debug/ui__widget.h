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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui__Widget
{
public:

    void setupUi(QWidget *_Widget)
    {
        if (_Widget->objectName().isEmpty())
            _Widget->setObjectName(QString::fromUtf8("_Widget"));
        _Widget->resize(800, 600);

        retranslateUi(_Widget);

        QMetaObject::connectSlotsByName(_Widget);
    } // setupUi

    void retranslateUi(QWidget *_Widget)
    {
        _Widget->setWindowTitle(QCoreApplication::translate("_Widget", "_Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class _Widget: public Ui__Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__WIDGET_H
