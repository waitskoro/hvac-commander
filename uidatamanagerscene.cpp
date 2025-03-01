#include "uidatamanagerscene.h"

#include "blockitem.h"
#include "common/triangle.h"
#include "common/custombutton.h"

UiDataManagerScene::UiDataManagerScene(QObject *parent)
    : QGraphicsScene(parent)
{
    createBlockManagerTemp();

    m_rightBlock = new BlockItem(800 / 2, 0, 800 / 2, 600);
    m_rightBlock->setHeaderName("Управление направлением подачи воздуха");
    addItem(m_rightBlock);
}

void UiDataManagerScene::createBlockManagerTemp()
{
    m_leftBlock = new BlockItem(0, 0, 800 / 2, 600);
    m_leftBlock->setHeaderName("Управление температурой");

    Triangle *triangleButtonUp = new Triangle(QPoint(100, 200),
                                              QPoint(200, 100),
                                              QPoint(300, 200));
    Triangle *triangleButtonUDown = new Triangle(QPoint(100, 300),
                                                 QPoint(200, 400),
                                                 QPoint(300, 300));

    addItem(triangleButtonUp);
    addItem(triangleButtonUDown);

    m_temperatureValueView = new QGraphicsTextItem("0");
    m_temperatureValueView->setDefaultTextColor(Qt::black);
    m_temperatureValueView->setFont(QFont("Arial", 40, QFont::Bold));

    QPointF blockCenter = m_leftBlock->rect().center();
    m_temperatureValueView->setPos(blockCenter.x() - 30, blockCenter.y() - 90);

    addItem(m_temperatureValueView);
    addItem(m_leftBlock);

    connect(triangleButtonUp,
            &Triangle::clicked,
            this,
            &UiDataManagerScene::temperatureUp);
    \
    connect(triangleButtonUDown,
            &Triangle::clicked,
            this,
            &UiDataManagerScene::temperatureDown);
}

void UiDataManagerScene::onTemperatureChanged(qint32 value)
{
    if (m_temperatureValueView) {
        m_temperatureValueView->setPlainText(QString::number(value));
    }
}
