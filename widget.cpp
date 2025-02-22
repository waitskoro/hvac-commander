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

    QLabel* pHeader = new QLabel();
    pHeader->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    pHeader->setMinimumSize(200, 50);

    QFont font = pHeader->font();
    font.setBold(true);
    font.setPointSizeF(14);
    pHeader->setFont(font);

    QHBoxLayout* pHeaderLayout = new QHBoxLayout;
    pHeaderLayout->setContentsMargins(10, 10, 10, 10);
    pHeaderLayout->setSpacing(30);

    m_temperatureLabel = new QLabel("Температура: 23°C");
    m_humidityLabel = new QLabel("Влажность: 50%");
    m_pressureLabel = new QLabel("Давление: 1000 гПа");

    pHeaderLayout->addStretch();
    pHeaderLayout->addWidget(m_temperatureLabel);
    pHeaderLayout->addWidget(m_humidityLabel);
    pHeaderLayout->addWidget(m_pressureLabel);
    pHeaderLayout->addStretch();

    pHeader->setLayout(pHeaderLayout);

    pBoxLayout->addWidget(pHeader);
    pBoxLayout->addStretch();

    QPushButton *settingsButton = new QPushButton(tr("Настройки"));
    connect(settingsButton, &QPushButton::clicked, this, &Widget::showSettingsDialog);
    pBoxLayout->addWidget(settingsButton);
}

void Widget::showSettingsDialog()
{
    SettingsDialog dialog(this);
    connect(&dialog, &SettingsDialog::parametersAccepted, this, &Widget::updateParameters);
    dialog.exec();
}

void Widget::updateParameters(double temperature, int humidity, int pressure)
{
    m_temperatureLabel->setText(QString("Температура: %1°C").arg(temperature));
    m_humidityLabel->setText(QString("Влажность: %1%").arg(humidity));
    m_pressureLabel->setText(QString("Давление: %1 гПа").arg(pressure));
}
