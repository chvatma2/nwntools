#include <QCoreApplication>
#include <QDir>
#include <QString>

#include <QDebug>

#include "src/core/ddsfile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc != 3)
    {
        qDebug() << "Incorrect number of parameters, usage: ddsconverter [in folder] [out folder]";
        return 1;
    }
    try
    {
        qDebug() << argv[1];
        QDir dir(argv[1]);
        dir.setNameFilters(QStringList()<<"*.dds");
        QStringList fileList = dir.entryList();
        qDebug() << fileList;
        dir.mkpath(argv[2]);
        for(QString str : fileList)
        {
           nwntools::DDSFile ddsfile(dir.path() + "/" + str);
           ddsfile.convert(argv[2]);
        }
        //nwntools::DDSFile ddsfile("C:/Users/martn/Downloads/dxtRBG.dds");
        //ddsfile.convert();
    }
    catch (std::runtime_error &e)
    {
        qDebug() << e.what();
    }

    return 0;
}
