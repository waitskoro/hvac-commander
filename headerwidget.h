#pragma once

#include <QWidget>
#include <QHBoxLayout>

#include "parameterwidget.h"

/**
 * @brief Класс HeaderWidget представляет виджет заголовка с отображением параметров.
 *
 * Класс отображает три параметра: температура, влажность и давление, используя виджеты ParameterWidget.
 * Параметры располагаются в горизонтальном макете с отступами и растяжками.
 */
class HeaderWidget : public QWidget {

public:
    /**
     * @brief Конструктор класса HeaderWidget.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    HeaderWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QHBoxLayout* layout = new QHBoxLayout(this);
        setMinimumSize(200, 30);
        layout->setContentsMargins(10, 10, 10, 10);
        layout->setSpacing(30);

        m_temperatureWidget = new ParameterWidget(Parameter { Type::Temperature, Units::Celsius, 23 });
        m_humidityLabel = new ParameterWidget(Parameter { Type::Humidity, Units::Percent, 60 });
        m_pressureWidget = new ParameterWidget(Parameter { Type::Pressure, Units::MMHg, 1000 });

        layout->addStretch();
        layout->addWidget(m_temperatureWidget);
        layout->addWidget(m_humidityLabel);
        layout->addWidget(m_pressureWidget);
        layout->addStretch();
    }

    /**
     * @brief Возвращает виджет для отображения температуры.
     * @return Указатель на виджет температуры.
     */
    ParameterWidget* temperatureWidget() const { return m_temperatureWidget; }

    /**
     * @brief Возвращает виджет для отображения влажности.
     * @return Указатель на виджет влажности.
     */
    ParameterWidget* humidityLabel() const { return m_humidityLabel; }

    /**
     * @brief Возвращает виджет для отображения давления.
     * @return Указатель на виджет давления.
     */
    ParameterWidget* pressureWidget() const { return m_pressureWidget; }

private:
    ParameterWidget *m_temperatureWidget; ///< Виджет для отображения температуры.
    ParameterWidget *m_humidityLabel;    ///< Виджет для отображения влажности.
    ParameterWidget *m_pressureWidget;   ///< Виджет для отображения давления.
};
