#include <QApplication>
#include "menu.h"
#include "newgamemenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;

    a.setApplicationDisplayName("Bomber");
    menu.show();
    return a.exec();
}
