#ifndef UIDATAMANAGERSCENE_H
#define UIDATAMANAGERSCENE_H

#include <QSlider>
#include <QObject>
#include <QGraphicsScene>

#include "enums.h"

class UiDataManagerScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit UiDataManagerScene(QObject *parent = nullptr);
    void onUnitChanged(Units unit);
signals:
    void temperatureChanged(double value);

private:
    struct UnitInfo {
        int min;
        int max;
        QString suffix;
        double scale;
    };

    UnitInfo getUnitInfo(Units unit);
    void updateSliderAndLabels(Units unit);
    void onSliderValueChanged(int value);

    QSlider *m_slider;
    QGraphicsSimpleTextItem *m_minTempLabel;
    QGraphicsSimpleTextItem *m_maxTempLabel;
    QGraphicsSimpleTextItem *m_sliderValueLabel;
    Units m_currentUnit;
};

#endif // UIDATAMANAGERSCENE_H
