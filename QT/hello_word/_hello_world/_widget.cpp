#include "_widget.h"
#include "ui__widget.h"
#include <QLabel>

_Widget::_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_Widget)
{
    ui->setupUi(this);

    QLabel* label=new QLabel(this);
    //QLabel label;栈上创建
    QString Qt="hello_world";
    //label->setText("hello_world");
    label->setText(Qt);


}

_Widget::~_Widget()
{
    delete ui;
}

