#ifndef DDSHANDLER_H
#define DDSHANDLER_H

#include <QObject>
#include <QUrl>

class DDSHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl inputFolder READ inputFolder WRITE setInputFolder NOTIFY inputFolderChanged)
    Q_PROPERTY(QUrl outputFolder READ outputFolder WRITE setOutputFolder NOTIFY outputFolderChanged)

public:
    explicit DDSHandler(QObject *parent = nullptr);

    QUrl inputFolder();
    void setInputFolder(const QUrl &inputFolder);

    QUrl outputFolder();
    void setOutputFolder(const QUrl &outputFolder);

signals:
    void inputFolderChanged();
    void outputFolderChanged();
    void fileConverted(QString fileName);

public slots:
    void onStartConversion();

private:
    QUrl m_inputFolder;
    QUrl m_outputFolder;
};

#endif // DDSHANDLER_H
