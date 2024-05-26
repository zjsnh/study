#include "widget.h"
#include "ui_widget.h"
#include<QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //
    ui->radioButton_male->clicked(true);
    ui->label->setText("您的性别为male");
    //禁用other选项

    //ui->radioButton_other->setEnabled(false);
    //Chickable 但是可以响应事件，只是无法显示点击标识
    //ui->radioButton_other->setCheckable(false);
    ui->radioButton_other->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_radioButton_male_clicked()
{
    ui->label->setText("您的性别为male");
}

void Widget::on_radioButton_female_clicked()
{
    ui->label->setText("您的性别为female");
}

void Widget::on_radioButton_other_clicked()
{
    ui->label->setText("您的性别为other");
}
