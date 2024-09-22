#pragma once
#include "point.h"

// Абстрактный класс для описания остальных объектов
class Shape
{
public:
	virtual ~Shape() = default;

	// Чисто виртуальная функция (геттер для координат)
	virtual Point getPosition() const = 0;
};