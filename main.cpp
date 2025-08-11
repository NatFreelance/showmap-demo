#include "mapwidgettool.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapWidgetTool w;
    w.show();
    return a.exec();
}
