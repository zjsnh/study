#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<this->windowOpacity();

    ui->pushButton_up->setToolTip("透明度增高");
    ui->pushButton_up->setToolTipDuration(3000);

    ui->pushButton_down->setToolTip("透明度降低");
    ui->pushButton_down->setToolTipDuration(3000);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{   float opacity=this->windowOpacity();

    if(opacity<1.0)
    {
        opacity+=0.1;
        this->setWindowOpacity(opacity);
    }
    else
    {
         qDebug()<<"透明度已经是最大";
    }

    qDebug()<<this->windowOpacity();
}

void Widget::on_pushButton_down_clicked()
{
    float opacity=this->windowOpacity();

        if(opacity>0.1)
        {
            opacity-=0.1;
            this->setWindowOpacity(opacity);
        }
        else
        {
             qDebug()<<"透明度已经是最小";
        }

        qDebug()<<this->windowOpacity();
}
