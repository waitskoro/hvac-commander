#pragma once

#include "enums.h"

struct Parameter {
    Type type;
    Units unit;
    double value;

    Parameter(Type t, Units u, double v) : type(t), unit(u), value(v) {}
};
