#include "application.h"

#include "settingsdialog.h"
#include "parameterwidget.h"
#include "uidatamanagerscene.h"

#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

Application::Application(QWidget *parent)
    : QWidget(parent)
    , m_parameterWidgets(new ParameterWidgetContainer(this))
    , m_uiDataManagerScene(new UiDataManagerScene(this))
{
    setMinimumHeight(600);
    setMinimumWidth(800);
    setMaximumHeight(768);
    setMinimumWidth(1024);

    setupMainLayout();
    connectSignalsAndSlots();
    setInitialValues();

    connect(m_uiDataManagerScene,
            &UiDataManagerScene::temperatureDown,
            m_parameterWidgets,
            [this](){
                int newValue = m_parameterWidgets->temperatureWidget()->getValue();
                m_parameterWidgets->temperatureWidget()->setValue(newValue - 1);
        });

    connect(m_uiDataManagerScene,
            &UiDataManagerScene::temperatureUp,
            m_parameterWidgets,
            [this](){
                int newValue = m_parameterWidgets->temperatureWidget()->getValue();
                m_parameterWidgets->temperatureWidget()->setValue(newValue + 1);
        });
}

void Application::setupMainLayout()
{
    QVBoxLayout* pBoxLayout = new QVBoxLayout(this);
    QGraphicsView *view = new QGraphicsView(m_uiDataManagerScene, this);
    QPushButton *settingsButton = new QPushButton(tr("Настройки"), this);

    pBoxLayout->addWidget(m_parameterWidgets);
    pBoxLayout->addWidget(view);
    pBoxLayout->addWidget(settingsButton);

    setLayout(pBoxLayout);
}

void Application::connectSignalsAndSlots()
{
    connect(m_parameterWidgets->temperatureWidget(),
            &ParameterWidget::valueChanged,
            this, [this]() {
                int newValue = m_parameterWidgets->temperatureWidget()->getValue();
                m_uiDataManagerScene->onTemperatureChanged(newValue);
            });

    QPushButton *settingsButton = findChild<QPushButton*>();
    connect(settingsButton,
            &QPushButton::clicked,
            this,
            &Application::showSettingsDialog);
}

void Application::setInitialValues()
{
    m_parameterWidgets->humidityLabel()->setValue(60);
    m_parameterWidgets->pressureWidget()->setValue(1010);
    m_parameterWidgets->temperatureWidget()->setValue(25.0);
}

void Application::showSettingsDialog()
{
    SettingsDialog dialog(m_parameterWidgets->temperatureWidget()->getCurrentUnit(),
                          m_parameterWidgets->pressureWidget()->getCurrentUnit(),
                          this);
    connect(&dialog,
            &SettingsDialog::parametersAccepted,
            this,
            &Application::updateParameters);

    dialog.exec();
}

void Application::updateParameters(double temperature, int humidity, int pressure)
{
    m_parameterWidgets->humidityLabel()->setValue(humidity);
    m_parameterWidgets->pressureWidget()->setValue(pressure);
    m_parameterWidgets->temperatureWidget()->setValue(temperature);
}
