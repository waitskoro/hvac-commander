#include "settingsdialog.h"

#include <QMessageBox>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
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
    if (!ok || temperature < -100 || temperature > 100) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Неверное значение температуры."));
        return;
    }

    int humidity = m_humidityInput->text().toInt(&ok);
    if (!ok || humidity < 0 || humidity > 100) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Неверное значение влажности."));
        return;
    }

    int pressure = m_pressureInput->text().toInt(&ok);
    if (!ok || pressure < 900 || pressure > 1100) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Неверное значение давления."));
        return;
    }

    emit parametersAccepted(temperature, humidity, pressure);
    QDialog::accept();
}
