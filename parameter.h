#pragma once

#include "enums.h"

struct Parameter {
    Type type;
    Units unit;
    int value;

    Parameter(Type t, Units u, int v)
        : type(t), unit(u), value(v) {}
};
