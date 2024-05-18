#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void mySignals(int i=0);

    void mysignal1();
    void mysignal2();

public:
    void handlmySignals(int i=0);
    void handleClick();

    void handleClick1();
    void handleClick2();




private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
