#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<fstream>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //文件操作
    File();
}

Widget::~Widget()
{
    delete ui;
}


bool Widget::File()
{
    std::ifstream file("E:/2023_code/study/QT/comboBox/config.txt");//E:/2023_code/study/QT/comboBox/
    if(!file.is_open())
    {
        qDebug()<<"文件打开失败";
        return false;
    }

    std::string line;
    while(std::getline(file,line))
    {
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    file.close();
    return true;
}

