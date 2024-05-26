#include "widget.h"
#include "ui_widget.h"
#include<QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
   QString string("今天小郑的安排是：");
    if(ui->checkBox->isChecked())
    {
        string+=ui->checkBox->text()+" ";
    }

    if(ui->checkBox_2->isChecked())
    {
        string+=ui->checkBox_2->text()+" ";
    }

    if(ui->checkBox_3->isChecked())
    {
        string+=ui->checkBox_3->text()+" ";
    }

    ui->label->setText(string);

}
