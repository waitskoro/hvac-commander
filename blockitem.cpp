#include "blockitem.h"

BlockItem::BlockItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, width, height, parent)
    , m_textWrapper(this)
{
}

void BlockItem::setHeaderName(const QString& name)
{
    QFont headerFont;
    headerFont.setBold(true);
    headerFont.setPointSize(14);

    m_textWrapper.setText(name, headerFont, rect().width());
    m_textWrapper.setPosition(rect().x(), rect().y() + 20);
}
