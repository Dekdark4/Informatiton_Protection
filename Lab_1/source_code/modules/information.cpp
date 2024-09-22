#include "information.h"

// Конструктор по умолчанию
Information::Information(double x, double y) : position(x, y) { }

// Геттер для координат источника информации
Point Information::getPosition() const { return position; }