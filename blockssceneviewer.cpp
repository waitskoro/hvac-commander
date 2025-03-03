#include "blockssceneviewer.h"

#include "blockitem.h"
#include "common/triangle.h"

BlockSceneViewer::BlockSceneViewer(QObject *parent)
    : QGraphicsScene(parent)
{
    createBlockManagerTemp();
    createBlockManagerAir();
}

void BlockSceneViewer::createBlockManagerTemp()
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
            [this]() {
        emit temperatureChange(Position::Up);
    });

    connect(triangleButtonUDown,
            &Triangle::clicked,
            this,
            [this]() {
        emit temperatureChange(Position::Down);
    });
}

void BlockSceneViewer::createBlockManagerAir()
{
    m_rightBlock = new BlockItem(800 / 2, 0, 800 / 2, 600);
    m_rightBlock->setHeaderName("Управление направлением подачи воздуха");
    addItem(m_rightBlock);

    Triangle *triangleButtonUp = new Triangle(QPoint(550, 200),
                                              QPoint(600, 150),
                                              QPoint(650, 200));
    Triangle *triangleButtonDown = new Triangle(QPoint(550, 300),
                                                 QPoint(600, 350),
                                                 QPoint(650, 300));

    Triangle *triangleButtonLeft = new Triangle(QPoint(500, 250),
                                              QPoint(550, 300),
                                              QPoint(550, 200));
    Triangle *triangleButtonRight = new Triangle(QPoint(700, 250),
                                                  QPoint(650, 300),
                                                  QPoint(650, 200));

    addItem(triangleButtonUp);
    addItem(triangleButtonDown);
    addItem(triangleButtonLeft);
    addItem(triangleButtonRight);



    connect(triangleButtonUp,
            &Triangle::clicked,
            this,
            [this]() {
        emit airChange(Position::Up);
    });

    connect(triangleButtonDown,
            &Triangle::clicked,
            this,
            [this]() {
        emit airChange(Position::Down);
    });

    connect(triangleButtonLeft,
            &Triangle::clicked,
            this,
            [this]() {
        emit airChange(Position::Left);
    });

    connect(triangleButtonRight,
            &Triangle::clicked,
            this,
            [this]() {
        emit airChange(Position::Right);
    });
}

void BlockSceneViewer::onTemperatureChanged(qint32 value)
{
    if (m_temperatureValueView)
        m_temperatureValueView->setPlainText(QString::number(value));
}
