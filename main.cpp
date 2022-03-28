#include "tag.h"
#include"game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tag w;
    w.show();
    return a.exec();
}
