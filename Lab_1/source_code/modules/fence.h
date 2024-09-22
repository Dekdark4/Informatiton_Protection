#pragma once
#include "shape.h"

// Класс для представления забора
class Fence : public Shape
{
public:
	Fence(double x, double y);
	Point getPosition() const override;
private:
	Point position;
};