#include "mainwindow.h"

#include "ddsconverterwidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(400, 600);
    m_centralStackedWidget = new QStackedWidget(this);
    createButtons();
    m_widgetMap[AvailableTools::MAINMENU] = m_menuButtonsGroup;
    m_centralStackedWidget->addWidget(m_menuButtonsGroup);
    setCentralWidget(m_centralStackedWidget);
    connectSlots();
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonClicked(int button)
{
    switch(button)
    {
    case static_cast<int>(AvailableTools::DDSCONVERTER):
        if(!m_widgetMap.contains(AvailableTools::DDSCONVERTER))
        {
            DDSConverterWidget* ddsconverter = new DDSConverterWidget();
            m_widgetMap[AvailableTools::DDSCONVERTER] = ddsconverter;
            m_centralStackedWidget->addWidget(ddsconverter);
            connect(ddsconverter, &DDSConverterWidget::backClicked, this, &MainWindow::onBackClicked);
        }
        m_centralStackedWidget->setCurrentWidget(m_widgetMap[AvailableTools::DDSCONVERTER]);
        break;
    default:
        qDebug() << "Unknowns button";
        break;
    }
}

void MainWindow::onBackClicked()
{
    m_centralStackedWidget->setCurrentWidget(m_widgetMap[AvailableTools::MAINMENU]);
}

void MainWindow::connectSlots()
{
    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &MainWindow::onButtonClicked);

}

void MainWindow::createButtons()
{
    m_buttonGroup = new QButtonGroup(this);
    m_mainLayout = new QVBoxLayout;
    m_menuButtonsGroup = new QGroupBox("Available Tools", this);

    QPushButton *ddsButton = new QPushButton("DDS Converter");
    m_buttonGroup->addButton(ddsButton, static_cast<int>(AvailableTools::DDSCONVERTER));
    m_mainLayout->addWidget(ddsButton);
    m_mainLayout->addStretch();
    m_menuButtonsGroup->setLayout(m_mainLayout);
}
