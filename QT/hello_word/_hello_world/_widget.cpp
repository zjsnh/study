#include "_widget.h"
#include "ui__widget.h"
#include <QLabel>
#include<QPushButton>

_Widget::_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::_Widget)
{
    ui->setupUi(this);


    //connect(ui->myButton,&QPushButton::clicked,this,&_Widget::handleClick);
    connect(ui->pushButton,&QPushButton::clicked,this,&_Widget::handleClick);

    QPushButton* myButton=new QPushButton(this);
    QString q("hello world");
    myButton->setText(q);



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

