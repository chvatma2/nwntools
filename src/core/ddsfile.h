#ifndef DDSFILE_H
#define DDSFILE_H

#include <QString>
#include <QFile>

namespace nwntools {

class DDSFile
{
public:
    DDSFile(const QString &filename);
    void convert(const QString &outputFolder);

private:
    QFile m_file;
};

}


#endif // DDSFILE_H
