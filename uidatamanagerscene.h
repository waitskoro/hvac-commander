#pragma once

#include <QLabel>
#include <QSlider>
#include <QObject>
#include <QPushButton>
#include <QGraphicsScene>

#include "enums.h"

class BlockItem;

class UiDataManagerScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit UiDataManagerScene(QObject *parent = nullptr);

    void onTemperatureChanged(qint32 value);

signals:
    void temperatureUp();
    void temperatureDown();

private:
    BlockItem* m_leftBlock;
    BlockItem* m_rightBlock;

    QPushButton *m_button;

    QGraphicsTextItem *m_temperatureValueView;

    void createBlockManagerTemp();
};
