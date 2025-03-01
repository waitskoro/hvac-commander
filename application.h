#ifndef APPLICATION_H
#define APPLICATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class HeaderWidget;
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

    void setupMainLayout();
    void setInitialValues();

private:
    HeaderWidget *m_parameterWidgets;
    QPushButton *m_settingsButton;
    SettingsDialog *m_dialog;
    UiDataManagerScene *m_uiDataManagerScene;
};

#endif // APPLICATION_H
