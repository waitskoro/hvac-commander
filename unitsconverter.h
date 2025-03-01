#ifndef UNITSCONVERTER_H
#define UNITSCONVERTER_H

#include <QString>

class UnitsConverter {
public:
    static int celsiusToKelvin(int celsius);
    static int celsiusToFahrenheit(int celsius);

    static int fahrenheitToKelvin(int fahrenheit);
    static int fahrenheitToCelsius(int fahrenheit);

    static int kelvinToCelsius(int kelvin);
    static int kelvinToFahrenheit(int kelvin);

    static int pascalToMMHg(int pascal);
    static int mmHgToPascal(int mmHg);
};

#endif // UNITSCONVERTER_H
