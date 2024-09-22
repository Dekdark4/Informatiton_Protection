#pragma once
#include <iostream>

// Класс для работы с координатами
class Point
{
public:
	Point();

	template <typename T>
	Point(T x, T y);

	static double getDistance(const Point& A, const Point& B);

	template <typename T>
	void incPoint(const T index);

	template <typename T>
	void incPointX(const T index);

	template <typename T>
	void incPointY(const T index);

	double getX() const;
	double getY() const;

private:
	double x;
	double y;
};


template <typename T>
Point::Point(T x, T y) : x(static_cast<double>(x)), y(static_cast<double>(y)) { }

// Увеличение координат (для проходки по ним)
template <typename T>
void Point::incPoint(const T index)
{
	x += static_cast<double>(index);
	y += static_cast<double>(index);
}

// Увеличение координаты x (для проходки)
template <typename T>
void Point::incPointX(const T index)
{
	x += static_cast<double>(index);
}

// Увеличение координаты y (для проходки)
template <typename T>
void Point::incPointY(const T index)
{
	y += static_cast<double>(index);
}