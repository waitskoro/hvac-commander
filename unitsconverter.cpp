#include "unitsconverter.h"

double UnitsConverter::fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double UnitsConverter::fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

double UnitsConverter::celsiusToFahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

double UnitsConverter::celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double UnitsConverter::kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double UnitsConverter::kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

double UnitsConverter::pascalToMMHg(double pascal) {
    return pascal / 133.322;
}

double UnitsConverter::mmHgToPascal(double mmHg) {
    return mmHg * 133.322;
}
