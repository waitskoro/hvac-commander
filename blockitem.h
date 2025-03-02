#pragma once

#include <QGraphicsRectItem>
#include "common/textwrapper.h"

/**
 * @brief Класс BlockItem представляет графический элемент прямоугольника с текстовым заголовком.
 *
 * Класс наследуется от QGraphicsRectItem и добавляет возможность отображения текстового заголовка
 * внутри прямоугольника с использованием класса TextWrapper.
 */
class BlockItem : public QGraphicsRectItem
{
public:
    /**
     * @brief Конструктор класса BlockItem.
     * @param x Координата X верхнего левого угла прямоугольника.
     * @param y Координата Y верхнего левого угла прямоугольника.
     * @param width Ширина прямоугольника.
     * @param height Высота прямоугольника.
     * @param parent Родительский графический элемент (по умолчанию nullptr).
     */
    BlockItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);

    /**
     * @brief Устанавливает текстовый заголовок для прямоугольника.
     * @param name Текст заголовка.
     */
    void setHeaderName(const QString& name);

private:
    TextWrapper m_textWrapper; ///< Объект для управления текстовым заголовком.
};
