#ifndef UNITSCONVERTER_H
#define UNITSCONVERTER_H

#include <QString>

/**
 * @brief Класс UnitsConverter предоставляет статические методы для конвертации единиц измерения.
 *
 * Класс содержит методы для преобразования температур между шкалами Цельсия, Фаренгейта и Кельвина,
 * а также для конвертации единиц давления между Паскалями и миллиметрами ртутного столба.
 */
class UnitsConverter {
public:
    /**
     * @brief Конвертирует температуру из градусов Цельсия в Кельвины.
     * @param celsius Температура в градусах Цельсия.
     * @return Температура в Кельвинах.
     */
    static int celsiusToKelvin(int celsius);

    /**
     * @brief Конвертирует температуру из градусов Цельсия в градусы Фаренгейта.
     * @param celsius Температура в градусах Цельсия.
     * @return Температура в градусах Фаренгейта.
     */
    static int celsiusToFahrenheit(int celsius);

    /**
     * @brief Конвертирует температуру из градусов Фаренгейта в Кельвины.
     * @param fahrenheit Температура в градусах Фаренгейта.
     * @return Температура в Кельвинах.
     */
    static int fahrenheitToKelvin(int fahrenheit);

    /**
     * @brief Конвертирует температуру из градусов Фаренгейта в градусы Цельсия.
     * @param fahrenheit Температура в градусах Фаренгейта.
     * @return Температура в градусах Цельсия.
     */
    static int fahrenheitToCelsius(int fahrenheit);

    /**
     * @brief Конвертирует температуру из Кельвинов в градусы Цельсия.
     * @param kelvin Температура в Кельвинах.
     * @return Температура в градусах Цельсия.
     */
    static int kelvinToCelsius(int kelvin);

    /**
     * @brief Конвертирует температуру из Кельвинов в градусы Фаренгейта.
     * @param kelvin Температура в Кельвинах.
     * @return Температура в градусах Фаренгейта.
     */
    static int kelvinToFahrenheit(int kelvin);

    /**
     * @brief Конвертирует давление из Паскалей в миллиметры ртутного столба.
     * @param pascal Давление в Паскалях.
     * @return Давление в миллиметрах ртутного столба.
     */
    static int pascalToMMHg(int pascal);

    /**
     * @brief Конвертирует давление из миллиметров ртутного столба в Паскали.
     * @param mmHg Давление в миллиметрах ртутного столба.
     * @return Давление в Паскалях.
     */
    static int mmHgToPascal(int mmHg);
};

#endif // UNITSCONVERTER_H
