#include "point.h"
#include <cmath>

// Конструктор по умолчанию
Point::Point() : x(0), y(0) { }

// Геттер для координаты x
double Point::getX() const
{
	return x;
}

// Геттер для координаты y
double Point::getY() const
{
	return y;
}

// Рассчёт дистанции между двумя точками
double Point::getDistance(const Point& A, const Point& B)
{
	return std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));
}