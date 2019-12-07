#include "brandscrabble.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BrandScrabble w;
    w.show();

    return a.exec();
}
