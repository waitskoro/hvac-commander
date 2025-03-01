#include "textwrapper.h"

#include <QBrush>

TextWrapper::TextWrapper(QGraphicsItem* parent)
    : m_parent(parent)
{
}

void TextWrapper::setText(const QString& text, const QFont& font, qreal blockWidth)
{
    clear();

    QFontMetrics fontMetrics(font);

    QStringList lines;
    QString currentLine;
    for (const QString& word : text.split(" ")) {
        if (fontMetrics.horizontalAdvance(currentLine + " " + word) <= blockWidth) {
            currentLine += (currentLine.isEmpty() ? "" : " ") + word;
        } else {
            lines.append(currentLine);
            currentLine = word;
        }
    }
    if (!currentLine.isEmpty()) {
        lines.append(currentLine);
    }

    for (const QString& line : lines) {
        QGraphicsSimpleTextItem* item = new QGraphicsSimpleTextItem(line, m_parent);
        item->setFont(font);
        item->setBrush(Qt::black);
        m_items.append(item);
    }
}

void TextWrapper::setPosition(qreal x, qreal y)
{
    qreal lineSpacing = 5;

    for (QGraphicsSimpleTextItem* item : m_items) {
        QRectF textRect = item->boundingRect();
        qreal xPos = x + (item->parentItem()->boundingRect().width() - textRect.width()) / 2;
        item->setPos(xPos, y);
        y += textRect.height() + lineSpacing;
    }
}

void TextWrapper::clear()
{
    for (QGraphicsSimpleTextItem* item : m_items) {
        delete item;
    }
    m_items.clear();
}

QList<QGraphicsSimpleTextItem*> TextWrapper::items() const
{
    return m_items;
}
