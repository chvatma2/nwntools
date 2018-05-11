#include "mainwindow.h"

#include <QHBoxLayout>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QDebug>

#include "ddsfile.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_mainLayout = new QVBoxLayout;
    m_centralWidget = new QWidget(this);

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

    m_centralWidget->setLayout(m_mainLayout);

    setCentralWidget(m_centralWidget);

    connect(m_inputSelect, &QPushButton::clicked, this, &MainWindow::onInputFolderClicked);
    connect(m_outputSelect, &QPushButton::clicked, this, &MainWindow::onOutputFolderClicked);
    connect(m_startConversion, &QPushButton::clicked, this, &MainWindow::onStartConversion);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onInputFolderClicked()
{
    QString selectedFolder = QFileDialog::getExistingDirectory();
    m_inputLine->setText(selectedFolder);
}

void MainWindow::onOutputFolderClicked()
{
    QString selectedFolder = QFileDialog::getExistingDirectory();
    m_outputLine->setText(selectedFolder);
}

void MainWindow::onStartConversion()
{
    try
    {
        QDir dir(m_inputLine->text());
        dir.setNameFilters(QStringList()<<"*.dds");
        QStringList fileList = dir.entryList();
        dir.mkpath(m_outputLine->text());
        for(QString str : fileList)
        {
           m_console->insertPlainText("Converting " + dir.path() + "/" + str + "\n");
           nwntools::DDSFile ddsfile(dir.path() + "/" + str);
           ddsfile.convert(m_outputLine->text());
        }
    }
    catch (std::runtime_error &e)
    {
        qDebug() << e.what();
    }
}
