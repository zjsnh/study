#include "_widget.h"
#include <QApplication> //添加"按钮" 头文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _Widget w;
    w.show();
    return a.exec();
}
