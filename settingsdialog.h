#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "common/enums.h"

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(const Units temperatureParam,
                            const Units pressureParam,
                            QWidget *parent = nullptr);

signals:
    void parametersAccepted(double temperature, int humidity, int pressure);

private slots:
    void accept();

private:
    QLineEdit *m_temperatureInput;
    QLineEdit *m_humidityInput;
    QLineEdit *m_pressureInput;

    Units m_tempUnit;
    Units m_pressUnit;

    bool isValidHumidity(int humidity);
    bool isValidPressure(int pressure);
    bool isValidTemperature(double temperature);
    void showError(const QString& paramName, const QString& message);
};

#endif // SETTINGSDIALOG_H
