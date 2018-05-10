#include "mainwindow.h"
#include <QApplication>

#include "ddsfile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    nwntools::DDSFile file("input");

    return a.exec();
}
