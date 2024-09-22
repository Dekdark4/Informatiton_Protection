#pragma once
#include "shape.h"

// Класс для представления источника информации
class Information : public Shape
{
public:
	Information(double x, double y);
	Point getPosition() const override;
private:
	Point position;
};