#include "_widget.h"
#include "ui__widget.h"

_Widget::_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_Widget)
{
    ui->setupUi(this);
}

_Widget::~_Widget()
{
    delete ui;
}

