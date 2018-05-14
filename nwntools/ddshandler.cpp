#include "ddshandler.h"

#include <QDir>
#include <QStringList>
#include <QDebug>

#include "ddsfile.h"

DDSHandler::DDSHandler(QObject *parent) : QObject(parent)
{

}

QUrl DDSHandler::inputFolder()
{
    return m_inputFolder;
}

void DDSHandler::setInputFolder(const QUrl &inputFolder)
{
    m_inputFolder = inputFolder;
    emit inputFolderChanged();
}

QUrl DDSHandler::outputFolder()
{
    return m_outputFolder;
}

void DDSHandler::setOutputFolder(const QUrl &outputFolder)
{
    m_outputFolder = outputFolder;
    emit outputFolderChanged();
}

void DDSHandler::onStartConversion()
{
    QDir inputDir(m_inputFolder.toLocalFile());
    inputDir.setNameFilters(QStringList()<<"*.dds");
    QStringList fileList = inputDir.entryList();
    try{
        for(QString str : fileList)
        {

            nwntools::DDSFile ddsfile(inputDir.path() + "/" + str);
            ddsfile.convert(m_outputFolder.toLocalFile());
            emit fileConverted(str);
        }
    }
    catch(const std::runtime_error &e)
    {
        qDebug() << e.what();
    }
}
