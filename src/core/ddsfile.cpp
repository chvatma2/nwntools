#include "ddsfile.h"

#include <QDataStream>
#include <QtEndian>
#include <QDebug>
#include <QVector>
#include <QFileInfo>

#include <exception>

namespace nwntools {

DDSFile::DDSFile(const QString &filename)
    : m_file(filename)
{
}

void DDSFile::convert(const QString &outputFolder)
{
    if(!m_file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Unable to open file: " + m_file.fileName().toUtf8());
    }
    uint32_t tmp;

    QDataStream stream(&m_file);

    QVector<uint32_t> header;
    for(int i = 0; i < 32; ++i)
    {
        stream >> tmp;
        header.push_back(tmp);
    }
    QFileInfo info(m_file);
    QFile convertedFile(outputFolder + "/" + info.fileName());
    if(!convertedFile.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error("Unable to open file: " + m_file.fileName().toUtf8());
    }
    QDataStream outputStream(&convertedFile);
    outputStream << header[3] << header[4] << header[20] << header[5] << 0x0000803f;
    while(stream.status() == QDataStream::Ok)
    {
        stream >> tmp;
        if(stream.status() == QDataStream::ReadPastEnd)
            break;
        outputStream << tmp;
    }

}

}
