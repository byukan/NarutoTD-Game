/** @mainpage PIC 10C hw10
@author Justin Wang
@id 604219879
@date 6/2/15

Naruto Tower Defense Game

Main creates the MainWindow, which displays the start menu and button.
*/

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.move(20,20);
    w.show();

    return a.exec();
}
