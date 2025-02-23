#include "settingsdialog.h"

#include "enums.h"
#include <QMessageBox>

SettingsDialog::SettingsDialog(Units temperatureUnit,
                               Units pressureUnit,
                               QWidget *parent)
    : QDialog(parent)
    , m_tempUnit(temperatureUnit)
    , m_pressUnit(pressureUnit)
{
    setWindowTitle(tr("Настройки"));

    m_temperatureInput = new QLineEdit;
    m_humidityInput = new QLineEdit;
    m_pressureInput = new QLineEdit;

    QPushButton *okButton = new QPushButton(tr("OK"));
    QPushButton *cancelButton = new QPushButton(tr("Cancel"));

    connect(okButton, &QPushButton::clicked, this, &SettingsDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Температура:"), m_temperatureInput);
    formLayout->addRow(tr("Влажность:"), m_humidityInput);
    formLayout->addRow(tr("Давление:"), m_pressureInput);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void SettingsDialog::accept()
{
    bool ok;
    double temperature = m_temperatureInput->text().toDouble(&ok);
    if (!ok) {
        showError("Температура", "Неверное значение температуры.");
        return;
    }

    int humidity = m_humidityInput->text().toInt(&ok);
    if (!ok || !isValidHumidity(humidity)) {
        showError("Влажность", "Неверное значение влажности.");
        return;
    }

    int pressure = m_pressureInput->text().toInt(&ok);
    if (!ok || !isValidPressure(pressure)) {
        showError("Давление", "Неверное значение давления.");
        return;
    }

    emit parametersAccepted(temperature, humidity, pressure);
    QDialog::accept();
}

bool SettingsDialog::isValidHumidity(int humidity)
{
    return humidity >= 0 && humidity <= 100;
}

bool SettingsDialog::isValidPressure(int pressure)
{
    if (m_pressUnit == Units::MMHg) {
        return pressure >= 900 && pressure <= 1100;
    } else if (m_pressUnit == Units::Pascal) {
        return pressure >= 120000 && pressure <= 146666;
    }
    return false;
}

bool SettingsDialog::isValidTemperature(double temperature)
{
    if (m_tempUnit == Units::Celsius) {
        return temperature >= -100 && temperature <= 100;
    } else if (m_tempUnit == Units::Fahrenheit) {
        return temperature >= -148 && temperature <= 212;
    } else if (m_tempUnit == Units::Kelvin) {
        return temperature >= 173.15 && temperature <= 373.15;
    }
    return false;
}

void SettingsDialog::showError(const QString& paramName, const QString& message)
{
    QMessageBox::warning(this, tr("Ошибка"), tr("%1: %2").arg(paramName, message));
}
