#pragma once

#include <QGraphicsRectItem>
#include "textwrapper.h"

class BlockItem : public QGraphicsRectItem
{
public:
    BlockItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);
    void setHeaderName(const QString& name);

private:
    TextWrapper m_textWrapper;
};

