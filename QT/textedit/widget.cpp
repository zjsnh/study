#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

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


void Widget::on_textEdit_textChanged()
{
    //ui->label->setText(ui->textEdit->toPlainText());
    qDebug()<<"textChange"<<ui->textEdit->toPlainText();
}


void Widget::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor=ui->textEdit->textCursor();
    qDebug()<<cursor.position();
}

void Widget::on_textEdit_selectionChanged()
{
    QTextCursor cursor=ui->textEdit->textCursor();
    qDebug()<<cursor.selectedText();
}

void Widget::on_textEdit_undoAvailable(bool b)
{
    qDebug()<<"undo_bool:"<<b;
}

void Widget::on_textEdit_redoAvailable(bool b)
{
    qDebug()<<"rado_bool:"<<b;
}

void Widget::on_textEdit_copyAvailable(bool b)
{
    qDebug()<<"copy_bool:"<<b;
}
