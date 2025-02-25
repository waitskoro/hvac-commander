#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class SettingsDialog;
class ParameterWidget;
class UiDataManagerScene;

class Application : public QWidget {
    Q_OBJECT

public:
    explicit Application(QWidget *parent = nullptr);

signals:
    void parametersChanged(double temperature, int humidity, int pressure);

private slots:
    void showSettingsDialog();
    void updateParameters(double temperature, int humidity, int pressure);

private:
    QLabel *m_header;

    ParameterWidget *m_humidityLabel;
    ParameterWidget *m_pressureWidget;
    ParameterWidget *m_temperatureWidget;

    UiDataManagerScene *m_uiDataManagerScene;

};

#endif // APPLICATION_H
