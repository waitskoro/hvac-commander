#ifndef UIDATAMANAGERSCENE_H
#define UIDATAMANAGERSCENE_H

#include <QSlider>
#include <QObject>
#include <QGraphicsScene>

class UiDataManagerScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit UiDataManagerScene(QObject *parent = nullptr);

signals:
    void temperatureChanged(double value);

private:
    QSlider *m_slider;
    QGraphicsSimpleTextItem *m_minTempLabel;
    QGraphicsSimpleTextItem *m_maxTempLabel;
    QGraphicsSimpleTextItem *m_sliderValueLabel;
};

#endif // UIDATAMANAGERSCENE_H
