#include <QtGui/QApplication>
#include "widget.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
