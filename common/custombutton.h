#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPen>
#include <QDebug>

class CustomButton : public QGraphicsRectItem {

public:
    CustomButton(const QRectF &rect, const QString &text, QGraphicsItem *parent = nullptr)
        : QGraphicsRectItem(rect, parent) {
        setPen(QPen(Qt::black, 2));
        setBrush(Qt::lightGray);

        buttonText = new QGraphicsTextItem(text, this);
        buttonText->setDefaultTextColor(Qt::black);
        buttonText->setPos(rect.x() + 10, rect.y() + 2);

        setAcceptHoverEvents(true);
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        setBrush(Qt::darkGray); // Меняем цвет фона при нажатии
        QGraphicsRectItem::mousePressEvent(event);
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override {
        setBrush(Qt::lightGray); // Возвращаем цвет фона после отпускания
        QGraphicsRectItem::mouseReleaseEvent(event);
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override {
        setBrush(Qt::gray); // Меняем цвет фона при наведении
        QGraphicsRectItem::hoverEnterEvent(event);
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override {
        setBrush(Qt::lightGray); // Возвращаем цвет фона после ухода курсора
        QGraphicsRectItem::hoverLeaveEvent(event);
    }

private:
    QGraphicsTextItem *buttonText;
};
