#pragma once

#include <QStringList>
#include <QFontMetrics>
#include <QGraphicsSimpleTextItem>

class TextWrapper : public QObject
{
    Q_OBJECT

public:
    explicit TextWrapper(QGraphicsItem* parent = nullptr);

    void setText(const QString& text, const QFont& font, qreal blockWidth);
    void setPosition(qreal x, qreal y);
    void clear();

    QList<QGraphicsSimpleTextItem*> items() const;

private:
    QGraphicsItem* m_parent;
    QList<QGraphicsSimpleTextItem*> m_items;
};
