#include "uidatamanagerscene.h"
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsSimpleTextItem>
#include <cmath>

UiDataManagerScene::UiDataManagerScene(QObject *parent)
    : QGraphicsScene(parent), m_currentUnit(Units::Celsius)
{
    const int sceneWidth = 800;
    const int sceneHeight = 600;
    setSceneRect(0, 0, sceneWidth, sceneHeight);

    const int blockWidth = sceneWidth / 2;
    const int blockHeight = sceneHeight / 2;

    QGraphicsRectItem *block1 = addRect(0, 0, blockWidth, blockHeight, QPen(Qt::black), QBrush(Qt::gray));
    block1->setPos(0, 0);

    QGraphicsRectItem *block2 = addRect(0, 0, blockWidth, blockHeight, QPen(Qt::black), QBrush(Qt::lightGray));
    block2->setPos(sceneWidth / 2, 0);

    UnitInfo initialInfo = getUnitInfo(m_currentUnit);
    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setRange(initialInfo.min, initialInfo.max);
    QGraphicsProxyWidget *proxy = addWidget(m_slider);
    proxy->setPos(block1->rect().center().x() - m_slider->width()/2,
                  block1->rect().center().y());

    QGraphicsSimpleTextItem *headerLine1 = addSimpleText("Управление");
    QGraphicsSimpleTextItem *headerLine2 = addSimpleText("температурой");

    QFont headerFont;
    headerFont.setBold(true);
    headerFont.setPointSize(14);
    headerLine1->setFont(headerFont);
    headerLine2->setFont(headerFont);

    const qreal verticalSpacing = 10;
    qreal totalHeight = headerLine1->boundingRect().height() +
                       headerLine2->boundingRect().height() +
                       verticalSpacing;

    headerLine1->setPos(
        block1->rect().center().x() - headerLine1->boundingRect().width()/2,
        proxy->pos().y() - totalHeight - 30
    );

    headerLine2->setPos(
        block1->rect().center().x() - headerLine2->boundingRect().width()/2,
        headerLine1->pos().y() + headerLine1->boundingRect().height() + verticalSpacing
    );

    m_minTempLabel = addSimpleText(QString::number(initialInfo.min / initialInfo.scale, 'f', 0) + initialInfo.suffix);
    m_maxTempLabel = addSimpleText(QString::number(initialInfo.max / initialInfo.scale, 'f', 0) + initialInfo.suffix);

    m_minTempLabel->setPos(proxy->pos().x() - 40, proxy->pos().y() + m_slider->height());
    m_maxTempLabel->setPos(proxy->pos().x() + m_slider->width(), proxy->pos().y() + m_slider->height());

    m_sliderValueLabel = addSimpleText(QString::number(m_slider->value() / initialInfo.scale, 'f', 0) + initialInfo.suffix);
    m_sliderValueLabel->setPos(proxy->pos().x() + m_slider->width() / 2 - 15, proxy->pos().y() + m_slider->height() + 25);

    connect(m_slider, &QSlider::valueChanged, this, &UiDataManagerScene::onSliderValueChanged);
}

UiDataManagerScene::UnitInfo UiDataManagerScene::getUnitInfo(Units unit) {
    UnitInfo info;
    switch (unit) {
    case Units::Celsius:
        info.min = -100;
        info.max = 100;
        info.suffix = "°C";
        info.scale = 1.0;
        break;
    case Units::Fahrenheit:
        info.min = -148;
        info.max = 212;
        info.suffix = "°F";
        info.scale = 1.0;
        break;
    case Units::Kelvin:
        info.min = 17315;
        info.max = 37315;
        info.suffix = " K";
        info.scale = 100.0;
        break;
    }
    return info;
}

void UiDataManagerScene::onUnitChanged(Units unit) {
    if (unit == m_currentUnit) return;

    UnitInfo oldInfo = getUnitInfo(m_currentUnit);
    double oldValue = m_slider->value() / oldInfo.scale;
    double tempInCelsius;

    switch (m_currentUnit) {
    case Units::Celsius: tempInCelsius = oldValue; break;
    case Units::Fahrenheit: tempInCelsius = (oldValue - 32) * 5.0/9.0; break;
    case Units::Kelvin: tempInCelsius = oldValue - 273.15; break;
    }

    double newValueActual;
    switch (unit) {
    case Units::Celsius: newValueActual = tempInCelsius; break;
    case Units::Fahrenheit: newValueActual = (tempInCelsius * 9.0/5.0) + 32; break;
    case Units::Kelvin: newValueActual = tempInCelsius + 273.15; break;
    }

    UnitInfo newInfo = getUnitInfo(unit);
    int newValueScaled = static_cast<int>(std::round(newValueActual * newInfo.scale));

    m_currentUnit = unit;
    m_slider->setRange(newInfo.min, newInfo.max);
    m_slider->setValue(newValueScaled);

    m_minTempLabel->setText(QString::number(newInfo.min / newInfo.scale, 'f', (newInfo.scale == 1.0) ? 0 : 2) + newInfo.suffix);
    m_maxTempLabel->setText(QString::number(newInfo.max / newInfo.scale, 'f', (newInfo.scale == 1.0) ? 0 : 2) + newInfo.suffix);
}

void UiDataManagerScene::onSliderValueChanged(int value) {
    UnitInfo info = getUnitInfo(m_currentUnit);
    double actualValue = static_cast<double>(value) / info.scale;
    m_sliderValueLabel->setText(QString::number(actualValue, 'f', (info.scale == 1.0) ? 0 : 2) + info.suffix);
    emit temperatureChanged(actualValue);
}
