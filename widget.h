#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "parameterwidget.h"

class SettingsDialog;

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

signals:
    void parametersChanged(double temperature, int humidity, int pressure);

private slots:
    void showSettingsDialog();
    void updateParameters(double temperature, int humidity, int pressure);

private:
    QLabel *m_header;
    QLabel *m_humidityLabel;

    ParameterWidget *m_pressureWidget;
    ParameterWidget *m_temperatureWidget;
};

#endif // WIDGET_H
