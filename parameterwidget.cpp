#include "parameterwidget.h"
#include "unitsconverter.h"

#include <map>
#include <QDebug>
#include <QMouseEvent>

using ConverterFunc = double (*)(double);

ParameterWidget::ParameterWidget(Parameter parameter)
    : m_parameter(parameter)
{
    connect(this,
            &ParameterWidget::valueChanged,
            this,
            &ParameterWidget::setTextInLabel);
}

void ParameterWidget::setTextInLabel()
{
    static const std::map<Type, QString> typeNames = {
        {Type::Temperature, "Температура"},
        {Type::Pressure, "Давление"}
    };

    static const std::map<Units, QString> unitSuffixes = {
        {Units::Celsius, "°C"},
        {Units::Fahrenheit, "°F"},
        {Units::Kelvin, "K"},
        {Units::MMHg, "мм рт. ст."},
        {Units::Pascal, "Па"}
    };

    QString text = QString("%1: %2 %3")
                   .arg(typeNames.at(m_parameter.type))
                   .arg(m_parameter.value)
                   .arg(unitSuffixes.at(m_parameter.unit));

    setText(text);
}

double ParameterWidget::getValue() const
{
    return m_parameter.value;
}

void ParameterWidget::setValue(double value)
{
    m_parameter.value = value;
    emit valueChanged();
}

void ParameterWidget::mousePressEvent(QMouseEvent *event)
{
    static const std::array<Units, 3> tempUnits = { Units::Celsius, Units::Fahrenheit, Units::Kelvin };
    static const std::array<Units, 2> pressureUnits = { Units::MMHg, Units::Pascal };

    Units currentUnit = getCurrentUnit();

    int index = -1;
    if (m_parameter.type == Type::Temperature) {
        index = std::find(tempUnits.begin(), tempUnits.end(), currentUnit) - tempUnits.begin();
    } else if (m_parameter.type == Type::Pressure) {
        index = std::find(pressureUnits.begin(), pressureUnits.end(), currentUnit) - pressureUnits.begin();
    }

    if (index >= 0) {
        if (m_parameter.type == Type::Temperature) {
            index = (index + 1) % tempUnits.size();
            changeUnit(tempUnits[index]);
        } else if (m_parameter.type == Type::Pressure) {
            index = (index + 1) % pressureUnits.size();
            changeUnit(pressureUnits[index]);
        }
    }

    event->accept();
}

void ParameterWidget::changeUnit(const Units newUnit)
{
    if (newUnit == m_parameter.unit)
        return;

    static const std::map<std::pair<Units, Units>, ConverterFunc> converters = {
        {{Units::Celsius, Units::Fahrenheit}, UnitsConverter::celsiusToFahrenheit},
        {{Units::Celsius, Units::Kelvin},     UnitsConverter::celsiusToKelvin},
        {{Units::Fahrenheit, Units::Celsius}, UnitsConverter::fahrenheitToCelsius},
        {{Units::Fahrenheit, Units::Kelvin},  UnitsConverter::fahrenheitToKelvin},
        {{Units::Kelvin, Units::Celsius},     UnitsConverter::kelvinToCelsius},
        {{Units::Kelvin, Units::Fahrenheit},  UnitsConverter::kelvinToFahrenheit},
        {{Units::MMHg, Units::Pascal},        UnitsConverter::mmHgToPascal},
        {{Units::Pascal, Units::MMHg},        UnitsConverter::pascalToMMHg}
    };

    try {
        auto it = converters.find(std::make_pair(m_parameter.unit, newUnit));
        if (it != converters.end()) {
            m_parameter.value = it->second(m_parameter.value);
        } else {
            throw std::invalid_argument("Unsupported conversion");
        }
        m_parameter.unit = newUnit;
        setTextInLabel();
    } catch (const std::exception& e) {
        qWarning() << "Error during unit conversion:" << e.what();
    }
}

Units ParameterWidget::getCurrentUnit() const
{
    return m_parameter.unit;
}
