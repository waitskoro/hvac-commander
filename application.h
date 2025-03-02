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
class BlockSceneViewer;

/**
 * @brief Класс Application представляет главное окно приложения.
 *
 * Класс управляет основным интерфейсом пользователя, включая отображение параметров,
 * кнопку настроек и диалог настроек. Также он обрабатывает изменения параметров
 * и обновляет интерфейс в соответствии с ними.
 */
class Application : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Application.
     * @param parent Родительский виджет (по умолчанию nullptr).
     */
    explicit Application(QWidget *parent = nullptr);

signals:
    /**
     * @brief Сигнал, который испускается при изменении параметров.
     * @param temperature Новое значение температуры.
     * @param humidity Новое значение влажности.
     * @param pressure Новое значение давления.
     */
    void parametersChanged(double temperature, int humidity, int pressure);

private slots:
    /**
     * @brief Отображает диалог настроек.
     */
    void showSettingsDialog();

    /**
     * @brief Обновляет параметры в интерфейсе.
     * @param temperature Новое значение температуры.
     * @param humidity Новое значение влажности.
     * @param pressure Новое значение давления.
     */
    void updateParameters(double temperature, int humidity, int pressure);

    /**
     * @brief Настраивает основной макет интерфейса.
     */
    void setupMainLayout();

    /**
     * @brief Устанавливает начальные значения параметров.
     */
    void setInitialValues();

private:
    HeaderWidget *m_parameterWidgets; ///< Виджет для отображения параметров.
    QPushButton *m_settingsButton;    ///< Кнопка для открытия диалога настроек.
    SettingsDialog *m_dialog;         ///< Диалог настроек.
    BlockSceneViewer *m_uiDataManagerScene; ///< Виджет для отображения сцены с данными.
};

#endif // APPLICATION_H
