#ifndef _WIDGET_H
#define _WIDGET_H

#include <QWidget>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class _Widget; }
QT_END_NAMESPACE

class _Widget : public QWidget
{
    Q_OBJECT

public:
    _Widget(QWidget *parent = nullptr);
    ~_Widget();

    void handleClick();
    void myhandleClick();

private:
    Ui::_Widget *ui;

    QPushButton* myButton;
};
#endif // _WIDGET_H
