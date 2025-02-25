#include "uidatamanagerscene.h"

#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsSimpleTextItem>

UiDataManagerScene::UiDataManagerScene(QObject *parent)
    : QGraphicsScene(parent)
{
    // Определяем ширину и высоту сцены
    const int sceneWidth = 800;   // Ширина сцены
    const int sceneHeight = 600;  // Высота сцены

    setSceneRect(0, 0, sceneWidth, sceneHeight);  // Задаём размеры сцены

    // Вычисляем размеры блоков исходя из размеров сцены
    const int blockWidth = sceneWidth / 2;  // Ширина каждого блока равна половине ширины сцены
    const int blockHeight = sceneHeight / 2;  // Высота каждого блока равна половине высоты сцены

    // Создаём первый блок
    QGraphicsRectItem *block1 = addRect(0, 0, blockWidth, blockHeight, QPen(Qt::black), QBrush(Qt::gray));
    block1->setPos(0, 0);  // Первый блок занимает левую верхнюю половину сцены

    // Создаём второй блок
    QGraphicsRectItem *block2 = addRect(0, 0, blockWidth, blockHeight, QPen(Qt::black), QBrush(Qt::lightGray));
    block2->setPos(sceneWidth / 2, 0);  // Второй блок занимает правую верхнюю половину сцены

    // Создаем слайдер для регулировки температурой
    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(-40, 80);
    QGraphicsProxyWidget *proxy = addWidget(m_slider); // Объявление proxy здесь
    proxy->setPos(block1->rect().center().x() - m_slider->width()/2,
                  block1->rect().center().y());

    // Создаем заголовок с раздельными строками
    QGraphicsSimpleTextItem *headerLine1 = addSimpleText("Управление");
    QGraphicsSimpleTextItem *headerLine2 = addSimpleText("температурой");

    // Настройка общего шрифта
    QFont headerFont;
    headerFont.setBold(true);
    headerFont.setPointSize(14);
    headerLine1->setFont(headerFont);
    headerLine2->setFont(headerFont);

    // Рассчитываем позицию для первой строки
    const qreal verticalSpacing = 10;
    qreal totalHeight = headerLine1->boundingRect().height() +
                       headerLine2->boundingRect().height() +
                       verticalSpacing;

    // Позиционируем первую строку
    headerLine1->setPos(
        block1->rect().center().x() - headerLine1->boundingRect().width()/2,
        proxy->pos().y() - totalHeight - 30
    );

    // Позиционируем вторую строку под первой
    headerLine2->setPos(
        block1->rect().center().x() - headerLine2->boundingRect().width()/2,
        headerLine1->pos().y() + headerLine1->boundingRect().height() + verticalSpacing
    );

    // Метки минимальных и максимальных значений температуры
    m_minTempLabel = addSimpleText("-40°C");
    m_maxTempLabel = addSimpleText("+80°C");

    // Располагаем метки температуры вдоль оси X слайдера
    m_minTempLabel->setPos(proxy->pos().x() - 40, proxy->pos().y() + m_slider->height());
    m_maxTempLabel->setPos(proxy->pos().x() + m_slider->width(), proxy->pos().y() + m_slider->height());

    // Добавление метки текущего значения слайдера
    m_sliderValueLabel = addSimpleText(QString::number(m_slider->value()) + "°C");  // Начальное значение
    m_sliderValueLabel->setPos(proxy->pos().x() + m_slider->width() / 2 - 15, proxy->pos().y() + m_slider->height() + 25);  // Размещение ниже слайдера

    // Подключение сигнала изменения значения слайдера к слоту обновления метки
    connect(m_slider, &QSlider::valueChanged, this, [this](int value) {
        m_sliderValueLabel->setText(QString::number(value) + "°C");  // Обновляем текст метки
        emit temperatureChanged(value);
    });
}
