#pragma once

#include <QWidget>
#include <QHBoxLayout>

#include "parameterwidget.h"

class ParameterWidgetContainer : public QWidget {

public:
    ParameterWidgetContainer(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        setMinimumSize(200, 30);
        layout->setContentsMargins(10, 10, 10, 10);
        layout->setSpacing(30);

        m_temperatureWidget = new ParameterWidget(Parameter { Type::Temperature, Units::Celsius, 23 });
        m_humidityLabel = new ParameterWidget(Parameter { Type::Temperature, Units::Percent, 60 });
        m_pressureWidget = new ParameterWidget(Parameter { Type::Pressure, Units::MMHg, 1000 });

        layout->addStretch();
        layout->addWidget(m_temperatureWidget);
        layout->addWidget(m_humidityLabel);
        layout->addWidget(m_pressureWidget);
        layout->addStretch();
    }

    ParameterWidget* temperatureWidget() const { return m_temperatureWidget; }
    ParameterWidget* humidityLabel() const { return m_humidityLabel; }
    ParameterWidget* pressureWidget() const { return m_pressureWidget; }

private:
    ParameterWidget *m_temperatureWidget;
    ParameterWidget *m_humidityLabel;
    ParameterWidget *m_pressureWidget;
};
