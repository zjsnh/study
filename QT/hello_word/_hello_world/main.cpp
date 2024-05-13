#include "_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    _Widget w;
    w.show();
    return a.exec();
}
