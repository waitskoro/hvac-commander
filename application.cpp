#include "application.h"

#include "settingsdialog.h"
#include "parameterwidget.h"
#include "uidatamanagerscene.h"

#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

Application::Application(QWidget *parent)
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

    m_pressureWidget = new ParameterWidget(Parameter { Type::Pressure, Units::MMHg, 1000 });
    m_humidityLabel = new ParameterWidget(Parameter { Type::Temperature, Units::Percent, 60 });
    m_temperatureWidget = new ParameterWidget(Parameter { Type::Temperature, Units::Celsius, 23 });

    QHBoxLayout* pHeaderLayout = new QHBoxLayout;
    pHeaderLayout->setContentsMargins(10, 10, 10, 10);
    pHeaderLayout->setSpacing(30);

    pHeaderLayout->addStretch();
    pHeaderLayout->addWidget(m_temperatureWidget);
    pHeaderLayout->addWidget(m_humidityLabel);
    pHeaderLayout->addWidget(m_pressureWidget);
    pHeaderLayout->addStretch();

    m_uiDataManagerScene = new UiDataManagerScene(this);
    QGraphicsView *view = new QGraphicsView(m_uiDataManagerScene, this);

    pBoxLayout->addWidget(m_header);
    pBoxLayout->addLayout(pHeaderLayout);
    pBoxLayout->addWidget(view);
    pBoxLayout->addStretch();

    QPushButton *settingsButton = new QPushButton(tr("Настройки"));
    connect(settingsButton, &QPushButton::clicked, this, &Application::showSettingsDialog);
    pBoxLayout->addWidget(settingsButton);

    setLayout(pBoxLayout);

    m_humidityLabel->setValue(60);
    m_pressureWidget->setValue(1010);
    m_temperatureWidget->setValue(25.0);

    connect(m_uiDataManagerScene,
            &UiDataManagerScene::temperatureChanged,
            m_temperatureWidget,
            &ParameterWidget::setValue);

    connect(m_temperatureWidget,
            &ParameterWidget::unitChanged,
            m_uiDataManagerScene,
            &UiDataManagerScene::onUnitChanged);
}

void Application::showSettingsDialog()
{
    SettingsDialog dialog(m_temperatureWidget->getCurrentUnit(), m_pressureWidget->getCurrentUnit(), this);
    connect(&dialog, &SettingsDialog::parametersAccepted, this, &Application::updateParameters);
    dialog.exec();
}

void Application::updateParameters(double temperature, int humidity, int pressure)
{
    m_humidityLabel->setValue(humidity);
    m_pressureWidget->setValue(pressure);
    m_temperatureWidget->setValue(temperature);
}
