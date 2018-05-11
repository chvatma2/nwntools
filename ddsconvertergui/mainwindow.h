#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QGroupBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onInputFolderClicked();
    void onOutputFolderClicked();
    void onStartConversion();

private:
    QVBoxLayout *m_mainLayout;
    QWidget *m_centralWidget;
    QPushButton *m_inputSelect;
    QPushButton *m_outputSelect;
    QPushButton *m_startConversion;
    QLineEdit *m_inputLine;
    QLineEdit *m_outputLine;
    QPlainTextEdit *m_console;
    QGroupBox *m_inputGroup;
    QGroupBox *m_outputGroup;
};

#endif // MAINWINDOW_H
