#include "widget.h"
#include "ui_widget.h"
#include<QIcon>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Widget_set();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Widget_set()
{
    //使用绝对路径
//    QIcon icon("D:\\biz-paper-plane.png");
//    this->setWindowIcon(icon);

    //使用qrc文件
    QIcon icon(":/point.png");
    this->setWindowIcon(icon);

    QIcon icon_pushbutton(":/camera.png");
    ui->pushButton_up->setIcon(icon_pushbutton);
    ui->pushButton_up->setIconSize(QSize(20,20));
    //ui->pushButton_up->shortcut("");

    ui->pushButton_up->setToolTip("透明度增高");
    ui->pushButton_up->setToolTipDuration(3000);

    ui->pushButton_down->setToolTip("透明度降低");
    QPixmap pixmap(":/point.png");
    pixmap=pixmap.scaled(10,10);//设置tu图标大小


    QCursor cursor(pixmap);
    ui->pushButton_up->setCursor(pixmap);
    ui->pushButton_down->setCursor(pixmap);

    //ui->pushButton_up->set

}


void Widget::on_pushButton_up_clicked()
{
    if(this->windowOpacity()<1.0)
    {
        float opacity=this->windowOpacity()+0.1;
        this->setWindowOpacity(opacity);
    }
    else
    {
        qDebug()<<"透明度已是最大";
        return ;
    }
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
             return ;
        }

        qDebug()<<this->windowOpacity();
}
