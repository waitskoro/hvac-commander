#include "unitsconverter.h"

int UnitsConverter::fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int UnitsConverter::fahrenheitToKelvin(int fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

int UnitsConverter::celsiusToFahrenheit(int celsius) {
    return celsius * 9 / 5 + 32;
}

int UnitsConverter::celsiusToKelvin(int celsius) {
    return celsius + 273.15;
}

int UnitsConverter::kelvinToCelsius(int kelvin) {
    return kelvin - 273.15;
}

int UnitsConverter::kelvinToFahrenheit(int kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int UnitsConverter::pascalToMMHg(int pascal) {
    return pascal / 133.322;
}

int UnitsConverter::mmHgToPascal(int mmHg) {
    return mmHg * 133.322;
}
