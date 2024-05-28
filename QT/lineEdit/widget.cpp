#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit_account->setPlaceholderText("请输入账号");
    ui->lineEdit_account->setClearButtonEnabled(true);

    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password_2->setPlaceholderText("请输入密码");


    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_password_2->setClearButtonEnabled(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    ui->lineEdit_password_2->setEchoMode(QLineEdit::Password);

    connect(ui->lineEdit_password,&QLineEdit::textEdited,this,&Widget::onPasswordFieldsEdited);
    connect(ui->lineEdit_password_2,&QLineEdit::textEdited,this,&Widget::onPasswordFieldsEdited);


    //验证器
    QRegExp regExp("^1\\d{10}$");
    ui->lineEdit_phone->setValidator(new QRegExpValidator(regExp));

    ui->lineEdit_phone->setPlaceholderText("请输入电话号码");
    ui->lineEdit_password->setClearButtonEnabled(true);
    //ui->lineEdit_phone->setInputMask("000-0000-0000");
    ui->pushButton->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString string=ui->radioButton_male->isChecked()?"男" : "女";

    qDebug()<<"账号："<<ui->lineEdit_account->text()
           <<"密码："<<ui->lineEdit_password->text()
          <<"性别："<<string<<"电话"<<ui->lineEdit_phone->text();
}

void Widget::on_lineEdit_phone_textEdited(const QString &text)
{
    QString string=text;
    int pos=0;

    ui->pushButton->setEnabled(true);

//    //正则表达式验证
//    if(ui->lineEdit_phone->validator()->validate(string,pos)==QValidator::Acceptable)
//    {
//        //验证通过
//        ui->pushButton->setEnabled(true);
//    }else
//    {
//        ui->pushButton->setEnabled(false);
//    }
}

void Widget::onPasswordFieldsEdited()
{
    const QString password = ui->lineEdit_password->text();
    const QString password_2 = ui->lineEdit_password_2->text();

    ui->pushButton->setEnabled(password == password_2);
}


/*在 Qt 框架中，槽（slot）函数用来响应信号（signal）。
在这个例子中，textEdited 信号会在用户编辑文本时发出。
因为有两个不同的文本输入框（lineEdit_password 和 lineEdit_password_2），
我们需要为每一个输入框分别创建一个槽函数来处理其 textEdited 信号。*/

//void Widget::on_lineEdit_password_textEdited(const QString &arg1)
//{
//    (void) arg1;

//    const QString password=ui->lineEdit_password->text();
//    const QString password_2=ui->lineEdit_password_2->text();

//    if(password==password_2)
//    {
//       ui->pushButton->setEnabled(true);
//    }
//    else
//    {
//        ui->pushButton->setEnabled(false);
//    }

//}

//void Widget::on_lineEdit_password_2_textEdited(const QString &arg1)
//{
//    (void) arg1;

//    const QString password=ui->lineEdit_password->text();
//    const QString password_2=ui->lineEdit_password_2->text();

//    if(password==password_2)
//    {
//       ui->pushButton->setEnabled(true);
//    }
//    else
//    {
//        ui->pushButton->setEnabled(false);
//    }
//}


