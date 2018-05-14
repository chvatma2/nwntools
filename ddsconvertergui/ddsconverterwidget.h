#ifndef DDSCONVERTERWIDGET_H
#define DDSCONVERTERWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QGroupBox>

class DDSConverterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DDSConverterWidget(QWidget *parent = nullptr);

signals:
    void backClicked();

public slots:
    void onInputFolderClicked();
    void onOutputFolderClicked();
    void onStartConversion();

private:
    QVBoxLayout *m_mainLayout;
    QPushButton *m_inputSelect;
    QPushButton *m_outputSelect;
    QPushButton *m_backButton;
    QPushButton *m_startConversion;
    QLineEdit *m_inputLine;
    QLineEdit *m_outputLine;
    QPlainTextEdit *m_console;
    QGroupBox *m_inputGroup;
    QGroupBox *m_outputGroup;
};

#endif // DDSCONVERTERWIDGET_H
