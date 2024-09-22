#include "building.h"

// Конструктор по умолчанию
Building::Building() { }

// Перегруженный конструктор для создания окон внутри здания
Building::Building(uint16_t x, uint16_t y)
{
	addWindow(Point(x, y));
}

// Геттер для координат здания
Point Building::getPosition() const { return position; }

// Метод для создания окна внутри здания (по координатам окна)
void Building::addWindow(uint16_t x, uint16_t y)
{
	windows.push_back(Point(x, y));
}

// Перегруженный метод для создания окна внутри здания (если окно — экземпляр класса Point)
void Building::addWindow(const Point& window)
{
	windows.push_back(window);
}

// Геттер для окон здания
const std::vector<Point>& Building::getWindows() const
{
	return windows;
}