#include "_widget.h"
#include "ui__widget.h"
#include <QLabel>
#include<QPushButton>

_Widget::_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_Widget)
{
    ui->setupUi(this);

    this->move(100,0);//控制weight在桌面的位置

    myButton=new QPushButton(this);
    QString q("hello world");
    myButton->setText(q);

    myButton->move(200,300);

    connect(myButton,&QPushButton::clicked,this,&_Widget::close);
    connect(ui->pushButton,&QPushButton::clicked,this,&_Widget::handleClick);

}

_Widget::~_Widget()
{
    delete ui;
}

void _Widget::handleClick()
{
   //ui->pushButton->setText("hello qt");

    if(ui->pushButton->text()==QString("ning wen bo"))
    {
        ui->pushButton->setText("sb");
    }
    else
    {
        ui->pushButton->setText("ning wen bo");
    }

}

void _Widget::myhandleClick()
{
    if(myButton->text()==QString("ning wen bo"))
    {
        myButton->setText("sb");
    }
    else
    {
        myButton->setText("ning wen bo");
    }
}

