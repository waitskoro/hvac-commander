#ifndef UNITSCONVERTER_H
#define UNITSCONVERTER_H

#include <QString>

class UnitsConverter {
public:
    static double celsiusToKelvin(double celsius);
    static double celsiusToFahrenheit(double celsius);

    static double fahrenheitToKelvin(double fahrenheit);
    static double fahrenheitToCelsius(double fahrenheit);

    static double kelvinToCelsius(double kelvin);
    static double kelvinToFahrenheit(double kelvin);

    static double pascalToMMHg(double pascal);
    static double mmHgToPascal(double mmHg);
};

#endif // UNITSCONVERTER_H
