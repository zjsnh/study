#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this,&Widget::mySignals,this,&Widget::handlmySignals);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handleClick);

    connect(this,&Widget::mysignal1,this,&Widget::handleClick1);
    connect(this,&Widget::mysignal1,this,&Widget::handleClick2);
    connect(this,&Widget::mysignal2,this,&Widget::handleClick1);
    connect(this,&Widget::mysignal2,this,&Widget::handleClick2);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::handlmySignals(int i)
{
    if(i==0)
    {
        this->setWindowTitle("窗口");
    }
    else
    {
        this->setWindowTitle("宁文博sb");
    }
    //this->setWindowTitle("窗口");
}

void Widget::handleClick()
{
    //emit mySignals();
    //mySignals(0);

    emit mysignal1();
    emit mysignal2();
}


void Widget::on_pushButton_2_clicked()
{
    mySignals(1);
}

void Widget::handleClick1()
{
    qDebug() <<"nihao";
}

void Widget::handleClick2()
{
    qDebug() <<"nihao";
}
