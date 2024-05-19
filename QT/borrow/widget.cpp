#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QTimer>
#include <cstdlib>
#include<QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(0));
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::clicked_close);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->label->setText("蟹蟹，支付宝还是微信");
}

void Widget::on_pushButton_2_pressed()
{
    //QRect rect=this->geometry();
    int wight=this->geometry().width();
    int height=this->geometry().height();

    //qDebug()<< wight<< height<<endl;

    int x=rand()%wight;
    int y=rand()%height;

    //qDebug()<< x<< y<<endl;

    ui->pushButton_2->move(x,y);
}

void Widget::clicked_close()
{

    QTimer::singleShot(3000, this, &Widget::close); // 6000 毫秒 = 6 秒
}
