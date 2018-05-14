#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QButtonGroup>
#include <QGroupBox>
#include <QMap>
#include <QStackedWidget>

enum class AvailableTools : int
{
    MAINMENU = 1,
    DDSCONVERTER
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onButtonClicked(int button);
    void onBackClicked();

private slots:

private:
    void connectSlots();
    void createButtons();

    QVBoxLayout *m_mainLayout;
    QGroupBox *m_menuButtonsGroup;
    QButtonGroup *m_buttonGroup;
    QMap<AvailableTools, QWidget*> m_widgetMap;
    QStackedWidget* m_centralStackedWidget;
};

#endif // MAINWINDOW_H
