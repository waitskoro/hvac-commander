#pragma once

#include <QStringList>
#include <QFontMetrics>
#include <QGraphicsSimpleTextItem>

/**
 * @brief Класс TextWrapper предназначен для управления текстовыми элементами на графической сцене.
 *
 * Класс позволяет устанавливать текст, шрифт, ширину блока, позицию, а также управлять списком текстовых элементов.
 */
class TextWrapper : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса TextWrapper.
     * @param parent Родительский графический элемент (по умолчанию nullptr).
     */
    explicit TextWrapper(QGraphicsItem* parent = nullptr);

    /**
     * @brief Устанавливает текст, шрифт и ширину блока для текстовых элементов.
     * @param text Текст, который будет отображаться.
     * @param font Шрифт, используемый для отображения текста.
     * @param blockWidth Ширина блока, в пределах которой текст будет переноситься.
     */
    void setText(const QString& text, const QFont& font, qreal blockWidth);

    /**
     * @brief Устанавливает позицию текстовых элементов на сцене.
     * @param x Координата X для позиционирования.
     * @param y Координата Y для позиционирования.
     */
    void setPosition(qreal x, qreal y);

    /**
     * @brief Очищает все текстовые элементы, удаляя их из сцены.
     */
    void clear();

    /**
     * @brief Возвращает список всех текстовых элементов.
     * @return Список указателей на QGraphicsSimpleTextItem.
     */
    QList<QGraphicsSimpleTextItem*> items() const;

private:
    QGraphicsItem* m_parent; ///< Указатель на родительский графический элемент.
    QList<QGraphicsSimpleTextItem*> m_items; ///< Список текстовых элементов.
};
