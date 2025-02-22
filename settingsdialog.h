#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>

class SettingsDialog : public QDialog {
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);

signals:
    void parametersAccepted(double temperature, int humidity, int pressure);

private slots:
    void accept();

private:
    QLineEdit *m_temperatureInput;
    QLineEdit *m_humidityInput;
    QLineEdit *m_pressureInput;
};

#endif // SETTINGSDIALOG_H
