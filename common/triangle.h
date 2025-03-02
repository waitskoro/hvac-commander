#pragma once

#include <QGraphicsObject>
#include <QPoint>
#include <QRectF>

/**
 * @brief Класс Triangle представляет собой треугольник, который может быть отображен на графической сцене.
 *
 * Класс наследуется от QGraphicsObject и позволяет задавать три точки для построения треугольника,
 * а также обрабатывать события мыши.
 */
class Triangle : public QGraphicsObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Triangle.
     * @param pointOne Первая точка треугольника.
     * @param pointTwo Вторая точка треугольника.
     * @param pointThree Третья точка треугольника.
     * @param parent Родительский графический элемент (по умолчанию nullptr).
     */
    Triangle(QPoint pointOne, QPoint pointTwo, QPoint pointThree, QGraphicsItem *parent = nullptr);

    /**
     * @brief Возвращает контур треугольника.
     * @return Контур треугольника в виде QPainterPath.
     */
    QPainterPath shape() const override;

    /**
     * @brief Возвращает ограничивающий прямоугольник треугольника.
     * @return Прямоугольник типа QRectF, который описывает границы треугольника.
     */
    QRectF boundingRect() const override;

    /**
     * @brief Отрисовывает треугольник на сцене.
     * @param painter Указатель на QPainter, используемый для отрисовки.
     * @param option Опции стиля для отрисовки.
     * @param widget Виджет, на котором происходит отрисовка (по умолчанию nullptr).
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    /**
     * @brief Сигнал, который испускается при нажатии на треугольник.
     */
    void clicked();

protected:
    /**
     * @brief Обрабатывает событие нажатия мыши на треугольник.
     * @param event Указатель на событие мыши.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPoint m_pointOne;   ///< Первая точка треугольника.
    QPoint m_pointTwo;   ///< Вторая точка треугольника.
    QPoint m_pointThree; ///< Третья точка треугольника.
};
