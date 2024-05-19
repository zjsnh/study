#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QRect>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->target->setEnabled(false);

    QPushButton* button =new QPushButton(this);
    button->setText("同意");
    button->move(400,200);


//         使用this传递 ui 成员
    connect(button, &QPushButton::clicked, this, [this]() {
//        if(button->text() == "ningwenbo") {
//            button->setText("sb");
//        }

        if(ui->target->isEnabled() == false) {
            ui->target->setEnabled(true);
        } else {
            ui->target->setEnabled(false);
        }
    });




}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    QRect rect=ui->target->geometry();

    //rect.setY(rect.y()-5);

    ui->target->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());

}

void Widget::on_pushButton_down_clicked()
{
    QRect rect=ui->target->geometry();

    //rect.setY(rect.y()+5);

    ui->target->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect=ui->target->geometry();

    //rect.setY(rect.x()-5);

    ui->target->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    QRect rect=ui->target->geometry();

    //rect.setY(rect.x()+5);

    ui->target->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}
