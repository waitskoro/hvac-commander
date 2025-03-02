#pragma once

#include <QLabel>
#include "common/enums.h"
#include "common/parameter.h"

/**
 * @brief Класс ParameterWidget представляет виджет для отображения и управления параметром.
 *
 * Класс наследуется от QLabel и позволяет отображать значение параметра, изменять его единицы измерения
 * и обрабатывать события мыши для взаимодействия с пользователем.
 */
class ParameterWidget : public QLabel {

    Q_OBJECT

public:
    /**
     * @brief Конструктор класса ParameterWidget.
     * @param parameter Параметр, который будет отображаться и управляться виджетом.
     */
    explicit ParameterWidget(Parameter parameter);

    /**
     * @brief Возвращает текущее значение параметра.
     * @return Значение параметра.
     */
    int getValue() const;

    /**
     * @brief Устанавливает новое значение параметра.
     * @param value Новое значение параметра.
     */
    void setValue(int value);

    /**
     * @brief Изменяет единицу измерения параметра.
     * @param unit Новая единица измерения.
     */
    void changeUnit(const Units unit);

    /**
     * @brief Возвращает текущую единицу измерения параметра.
     * @return Текущая единица измерения.
     */
    Units getCurrentUnit() const;

signals:
    /**
     * @brief Сигнал, который испускается при изменении значения параметра.
     */
    void valueChanged();

    /**
     * @brief Сигнал, который испускается при изменении единицы измерения параметра.
     * @param newUnit Новая единица измерения.
     */
    void unitChanged(Units newUnit);

protected:
    /**
     * @brief Обрабатывает событие нажатия мыши на виджет.
     * @param event Указатель на событие мыши.
     */
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    /**
     * @brief Обновляет текст, отображаемый на виджете, в соответствии с текущим значением и единицей измерения.
     */
    void setTextInLabel();

    Parameter m_parameter; ///< Параметр, который управляется и отображается виджетом.
};
