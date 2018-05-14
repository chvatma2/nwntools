#include "ddsconverterwidget.h"

#include <QHBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QPalette>
#include <QDebug>

#include "ddsfile.h"

DDSConverterWidget::DDSConverterWidget(QWidget *parent) : QWidget(parent)
{
    m_mainLayout = new QVBoxLayout;
    m_backButton = new QPushButton("Back");

    m_inputGroup = new QGroupBox("Input Folder");
    m_outputGroup = new QGroupBox("Output Folder");

    QHBoxLayout *inputLayout = new QHBoxLayout;
    QHBoxLayout *outputLayout = new QHBoxLayout;

    m_inputLine = new QLineEdit;
    m_inputSelect = new QPushButton("...");
    m_outputLine = new QLineEdit;
    m_outputSelect = new QPushButton("...");
    m_startConversion = new QPushButton("Start Conversion");

    inputLayout->addWidget(m_inputLine);
    inputLayout->addWidget(m_inputSelect);

    outputLayout->addWidget(m_outputLine);
    outputLayout->addWidget(m_outputSelect);

    m_inputGroup->setLayout(inputLayout);
    m_outputGroup->setLayout(outputLayout);

    m_mainLayout->addWidget(m_inputGroup);
    m_mainLayout->addWidget(m_outputGroup);
    m_console = new QPlainTextEdit;
    m_mainLayout->addWidget(m_startConversion);
    m_mainLayout->addWidget(m_console);
    m_mainLayout->addWidget(m_backButton);

    setLayout(m_mainLayout);

    connect(m_inputSelect, &QPushButton::clicked, this, &DDSConverterWidget::onInputFolderClicked);
    connect(m_outputSelect, &QPushButton::clicked, this, &DDSConverterWidget::onOutputFolderClicked);
    connect(m_startConversion, &QPushButton::clicked, this, &DDSConverterWidget::onStartConversion);
    connect(m_backButton, &QPushButton::clicked, this, &DDSConverterWidget::backClicked);
    m_console->setReadOnly(true);
    QPalette p = m_console->palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::white);
    m_console->setPalette(p);
}

void DDSConverterWidget::onInputFolderClicked()
{
    QString selectedFolder = QFileDialog::getExistingDirectory();
    m_inputLine->setText(selectedFolder);
}

void DDSConverterWidget::onOutputFolderClicked()
{
    QString selectedFolder = QFileDialog::getExistingDirectory();
    m_outputLine->setText(selectedFolder);
}

void DDSConverterWidget::onStartConversion()
{
    try
    {
        QDir dir(m_inputLine->text());
        dir.setNameFilters(QStringList()<<"*.dds");
        QStringList fileList = dir.entryList();
        dir.mkpath(m_outputLine->text());
        for(QString str : fileList)
        {
            m_console->insertPlainText("Converting " + dir.path() + "/" + str + "... ");
            nwntools::DDSFile ddsfile(dir.path() + "/" + str);
            ddsfile.convert(m_outputLine->text());
            m_console->insertPlainText("finsihed\n");
        }
    }
    catch (std::runtime_error &e)
    {
        qDebug() << e.what();
    }
}
