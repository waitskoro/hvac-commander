#pragma once

#include <QLabel>
#include <QSlider>
#include <QObject>
#include <QPushButton>
#include <QGraphicsScene>

#include "common/enums.h"

class BlockItem;

/**
 * @brief Класс BlockSceneViewer представляет графическую сцену для управления блоками и отображения данных.
 *
 * Класс наследуется от QGraphicsScene и предоставляет функциональность для управления блоками,
 * отображения температуры и взаимодействия с пользователем через кнопки.
 */
class BlockSceneViewer : public QGraphicsScene
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса BlockSceneViewer.
     * @param parent Родительский объект (по умолчанию nullptr).
     */
    explicit BlockSceneViewer(QObject *parent = nullptr);

    /**
     * @brief Обрабатывает изменение температуры.
     * @param value Новое значение температуры.
     */
    void onTemperatureChanged(qint32 value);

signals:
    /**
     * @brief Сигнал, который испускается при изменении положения воздуха.
     * @param pos Позиция воздуха (например, влево или вправо).
     */
    void airChange(Position pos);

    /**
     * @brief Сигнал, который испускается при изменении температуры.
     * @param pos Позиция, к которой относится изменение температуры.
     */
    void temperatureChange(Position pos);

private:
    BlockItem* m_leftBlock;  ///< Левый блок на сцене.
    BlockItem* m_rightBlock; ///< Правый блок на сцене.

    QPushButton *m_button; ///< Кнопка для взаимодействия с пользователем.

    QGraphicsTextItem *m_temperatureValueView; ///< Элемент для отображения значения температуры.

    /**
     * @brief Создает блок для управления температурой.
     */
    void createBlockManagerTemp();

    /**
     * @brief Создает блок для управления воздухом.
     */
    void createBlockManagerAir();
};
