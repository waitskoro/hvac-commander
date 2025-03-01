#include "triangle.h"

#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>

Triangle::Triangle(QPoint pointOne, QPoint pointTwo, QPoint pointThree, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_pointOne(pointOne)
    , m_pointTwo(pointTwo)
    , m_pointThree(pointThree)
{
}

QRectF Triangle::boundingRect() const
{
    int minX = qMin(qMin(m_pointOne.x(), m_pointTwo.x()), m_pointThree.x());
    int minY = qMin(qMin(m_pointOne.y(), m_pointTwo.y()), m_pointThree.y());
    int maxX = qMax(qMax(m_pointOne.x(), m_pointTwo.x()), m_pointThree.x());
    int maxY = qMax(qMax(m_pointOne.y(), m_pointTwo.y()), m_pointThree.y());

    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << m_pointOne << m_pointTwo << m_pointThree;
    painter->setBrush(Qt::gray);
    painter->drawPolygon(polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QPainterPath Triangle::shape() const
{
    QPainterPath path;
    path.moveTo(m_pointOne);
    path.lineTo(m_pointTwo);
    path.lineTo(m_pointThree);
    path.closeSubpath();

    return path;
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
    QGraphicsItem::mousePressEvent(event);
}
