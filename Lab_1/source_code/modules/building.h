#pragma once
#include "shape.h"
#include <iostream>
#include <vector>
#include <cstdint>

// Класс для представления здания и его окон
class Building : public Shape
{
public:
	Building();
	Building(uint16_t x, uint16_t y);
	Point getPosition() const override;
	void addWindow(uint16_t x, uint16_t y);
	void addWindow(const Point& window);
	const std::vector<Point>& getWindows() const;
private:
	Point position;
	std::vector<Point> windows;
};