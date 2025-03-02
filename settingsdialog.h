#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "common/enums.h"

/**
 * @brief Класс SettingsDialog представляет диалоговое окно для настройки параметров.
 *
 * Класс позволяет пользователю вводить значения температуры, влажности и давления,
 * а также проверяет корректность введенных данных. При подтверждении данных
 * испускается сигнал с новыми значениями параметров.
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса SettingsDialog.
     * @param temperatureParam Единица измерения температуры.
     * @param pressureParam Единица измерения давления.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit SettingsDialog(const Units temperatureParam,
                            const Units pressureParam,
                            QWidget *parent = nullptr);

signals:
    /**
     * @brief Сигнал, который испускается при подтверждении введенных параметров.
     * @param temperature Значение температуры.
     * @param humidity Значение влажности.
     * @param pressure Значение давления.
     */
    void parametersAccepted(double temperature, int humidity, int pressure);

private slots:
    /**
     * @brief Обрабатывает подтверждение введенных данных.
     *
     * Проверяет корректность введенных значений и, если они корректны,
     * испускает сигнал parametersAccepted.
     */
    void accept();

private:
    QLineEdit *m_temperatureInput; ///< Поле ввода температуры.
    QLineEdit *m_humidityInput;    ///< Поле ввода влажности.
    QLineEdit *m_pressureInput;    ///< Поле ввода давления.

    Units m_tempUnit;  ///< Единица измерения температуры.
    Units m_pressUnit; ///< Единица измерения давления.

    /**
     * @brief Проверяет корректность значения влажности.
     * @param humidity Значение влажности.
     * @return true, если значение корректно, иначе false.
     */
    bool isValidHumidity(int humidity);

    /**
     * @brief Проверяет корректность значения давления.
     * @param pressure Значение давления.
     * @return true, если значение корректно, иначе false.
     */
    bool isValidPressure(int pressure);

    /**
     * @brief Проверяет корректность значения температуры.
     * @param temperature Значение температуры.
     * @return true, если значение корректно, иначе false.
     */
    bool isValidTemperature(double temperature);

    /**
     * @brief Отображает сообщение об ошибке для указанного параметра.
     * @param paramName Название параметра.
     * @param message Сообщение об ошибке.
     */
    void showError(const QString& paramName, const QString& message);
};

#endif // SETTINGSDIALOG_H
