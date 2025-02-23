#include "widget.h"
#include "settingsdialog.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(600);
    setMinimumWidth(800);
    setMaximumHeight(768);
    setMinimumWidth(1024);

    QVBoxLayout* pBoxLayout = new QVBoxLayout(this);

    m_header = new QLabel("Параметры системы");
    m_header->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    m_header->setMinimumSize(200, 50);

    QFont font = m_header->font();
    font.setBold(true);
    font.setPointSizeF(14);
    m_header->setFont(font);

    m_humidityLabel = new QLabel("Влажность: 60%");

    m_temperatureWidget = new ParameterWidget(Parameter { Type::Temperature, Units::Celsius, 23 });
    m_pressureWidget = new ParameterWidget(Parameter { Type::Pressure, Units::MMHg, 1000 });

    QHBoxLayout* pHeaderLayout = new QHBoxLayout;
    pHeaderLayout->setContentsMargins(10, 10, 10, 10);
    pHeaderLayout->setSpacing(30);

    pHeaderLayout->addStretch();
    pHeaderLayout->addWidget(m_temperatureWidget);
    pHeaderLayout->addWidget(m_humidityLabel);
    pHeaderLayout->addWidget(m_pressureWidget);
    pHeaderLayout->addStretch();

    pBoxLayout->addWidget(m_header);
    pBoxLayout->addLayout(pHeaderLayout);
    pBoxLayout->addStretch();

    QPushButton *settingsButton = new QPushButton(tr("Настройки"));
    connect(settingsButton, &QPushButton::clicked, this, &Widget::showSettingsDialog);
    pBoxLayout->addWidget(settingsButton);

    setLayout(pBoxLayout);

    m_temperatureWidget->setValue(25.0);
    m_pressureWidget->setValue(1010);
}

void Widget::showSettingsDialog()
{
    SettingsDialog dialog(m_temperatureWidget->getCurrentUnit(), m_pressureWidget->getCurrentUnit(), this);
    connect(&dialog, &SettingsDialog::parametersAccepted, this, &Widget::updateParameters);
    dialog.exec();
}

void Widget::updateParameters(double temperature, int humidity, int pressure)
{
    m_temperatureWidget->setValue(temperature);
    m_humidityLabel->setText(QString("Влажность: %1%").arg(humidity));
    m_pressureWidget->setValue(pressure);
}
