#include "fence.h"

// Конструктор по умолчанию
Fence::Fence(double x, double y) : position(x, y) { }

// Геттер для координат забора
Point Fence::getPosition() const
{
	return position;
}