#include "application.h"

#include "headerwidget.h"
#include "settingsdialog.h"
#include "parameterwidget.h"
#include "blockssceneviewer.h"

#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

Application::Application(QWidget *parent)
    : QWidget(parent)
    , m_parameterWidgets(new HeaderWidget(this))
    , m_settingsButton(new QPushButton(tr("Настройки"), this))
    , m_dialog(new SettingsDialog(m_parameterWidgets->temperatureWidget()->getCurrentUnit(),
                                  m_parameterWidgets->pressureWidget()->getCurrentUnit(),
                                  this))
    , m_uiDataManagerScene(new BlockSceneViewer(this))
{
    connect(m_dialog,
            &SettingsDialog::parametersAccepted,
            this,
            &Application::updateParameters);

    connect(m_settingsButton,
            &QPushButton::clicked,
            this,
            &Application::showSettingsDialog);

    connect(m_uiDataManagerScene,
            &BlockSceneViewer::temperatureChange,
            m_parameterWidgets,
            [this](Position pos){
                int newValue = m_parameterWidgets->temperatureWidget()->getValue();
                if (pos == Position::Down)
                    m_parameterWidgets->temperatureWidget()->setValue(newValue - 1);
                if(pos == Position::Up)
                    m_parameterWidgets->temperatureWidget()->setValue(newValue + 1);
            });

    connect(m_parameterWidgets->temperatureWidget(),
            &ParameterWidget::valueChanged,
            this, [this]() {
                int newValue = m_parameterWidgets->temperatureWidget()->getValue();
                m_uiDataManagerScene->onTemperatureChanged(newValue);
            });

    setupMainLayout();
    setInitialValues();
}

void Application::setupMainLayout()
{
    QVBoxLayout* pBoxLayout = new QVBoxLayout(this);
    QGraphicsView *view = new QGraphicsView(m_uiDataManagerScene, this);

    pBoxLayout->addWidget(m_parameterWidgets);
    pBoxLayout->addWidget(view);
    pBoxLayout->addWidget(m_settingsButton);

    setLayout(pBoxLayout);
}

void Application::setInitialValues()
{
    m_parameterWidgets->humidityLabel()->setValue(60);
    m_parameterWidgets->pressureWidget()->setValue(1010);
    m_parameterWidgets->temperatureWidget()->setValue(25.0);
}

void Application::showSettingsDialog()
{
    m_dialog->exec();
}

void Application::updateParameters(double temperature, int humidity, int pressure)
{
    m_parameterWidgets->humidityLabel()->setValue(humidity);
    m_parameterWidgets->pressureWidget()->setValue(pressure);
    m_parameterWidgets->temperatureWidget()->setValue(temperature);
}
