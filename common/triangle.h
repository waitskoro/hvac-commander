#pragma once

#include <QGraphicsObject>
#include <QPoint>
#include <QRectF>

class Triangle : public QGraphicsObject
{
    Q_OBJECT

public:
    Triangle(QPoint pointOne, QPoint pointTwo, QPoint pointThree, QGraphicsItem *parent = nullptr);

    QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPoint m_pointOne;
    QPoint m_pointTwo;
    QPoint m_pointThree;
};
