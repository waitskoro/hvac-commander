#pragma once

#include <QLabel>
#include "common/enums.h"
#include "common/parameter.h"

class ParameterWidget : public QLabel {

    Q_OBJECT

public:
    explicit ParameterWidget(Parameter parameter);

    int getValue() const;
    void setValue(int value);

    void changeUnit(const Units unit);
    Units getCurrentUnit() const;

signals:
    void valueChanged();
    void unitChanged(Units newUnit);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    void setTextInLabel();

    Parameter m_parameter;
};
