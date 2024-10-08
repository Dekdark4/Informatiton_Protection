#include <iostream>
#include <algorithm>
#include <locale>
#include <vector>
#include "modules/point.h"
#include "modules/shape.h"
#include "modules/fence.h"
#include "modules/building.h"
#include "modules/information.h"

const int16_t SEGMENTS = 100;

std::vector<double> calculateDistances(const std::vector<Shape*>& shapes, const Point& point);
double calculateProbability(double l1, double l2, double P, double k1, double k2);

int main()
{
	setlocale(LC_ALL, "rus");


	std::vector<Shape*> shapes;


  // ����������

  // ���� ��������� ������
	uint16_t x = 0, y = 0;

	do
	{
		std::cout << "������� {x} ����� ������ � {y} ������ ������:\t";
		std::cin >> x >> y;
	} while (x >= 50 || y >= 50 || y < 2 || x < 1);

	Fence* fence = new Fence(x, y);
	shapes.push_back(fence);

	Building* building = new Building();



	// ���� ��������� ������� ����
	do
	{
		std::cout << "������� {x} � {y} ������� ����:\t";
		std::cin >> x >> y;
	} while (y >= fence->getPosition().getY() || x < 0 || x > fence->getPosition().getX() || y < 1);
	building->addWindow(x, y);
	


	// ���� ��������� ������� ����
	do {
		std::cout << "������� {x} � {y} ������� ����:\t";
		std::cin >> x >> y;
	} while (y != building->getWindows()[0].getY() || x < 0 || x > fence->getPosition().getX() || x == building->getWindows()[0].getX());
	building->addWindow(x, y);

	shapes.push_back(building);



	// ���� ��������� ��������� ����������
	do
	{
		std::cout << "������� {x} � {y} ��������� ����������:\t";
		std::cin >> x >> y;
	} while (y >= building->getWindows()[0].getY() || x > fence->getPosition().getX());
	Information* information = new Information(x, y);
	shapes.push_back(information);



	// ���� ������������
	double P1 = 0, P2 = 0;
	do
	{
		std::cout << "������� ����������� ������������� ����� ������ {P1} � ������ {P2} ����:\t";
		std::cin >> P1 >> P2;
	} while (P1 < 0 || P2 < 0 || P1 > 1 || P2 > 1);
  // ����� ����������





  // ����������

	// ���������� ������������ ����������
	double l12 = Point::getDistance(building->getWindows()[0], information->getPosition());
	double l22 = Point::getDistance(building->getWindows()[1], information->getPosition());



	// ���������� ����
	double fenceLength = fence->getPosition().getX();
	double step = fenceLength / SEGMENTS;



	// ���������� ������������ ��� ������� i-�� �������
	std::vector<double> probabilities;
	double k1 = 2.0, k2 = 0.5;
	for (int16_t i = 0; i < SEGMENTS; ++i)
	{
		double currentX = i * step;
		Point currentFencePoint(currentX, fence->getPosition().getY());

		double l11 = Point::getDistance(currentFencePoint, building->getWindows()[0]);
		double l21 = Point::getDistance(currentFencePoint, building->getWindows()[1]);

		double Pi1 = calculateProbability(l11, l12, P1, k1, k2);
		double Pi2 = calculateProbability(l21, l22, P2, k1, k2);

		probabilities.push_back(std::min(Pi1, Pi2));
	}

	double minProbability = *std::min_element(probabilities.begin(), probabilities.end());

	std::cout << "����������� ��������:\t" << minProbability << std::endl;
  // ����� ����������





  // ����������

	// ������������ ������
	for (auto shape : shapes)
	{
		delete shape;
	}

	std::cin.get();
	std::cin.get();
	// ����������





	return 0;
}

std::vector<double> calculateDistances(const std::vector<Shape*>& shapes, const Point& point)
{
	std::vector<double> distances;
	for (const auto& shape : shapes)
	{
		distances.push_back(Point::getDistance(shape->getPosition(), point));
	}
	return distances;
}

double calculateProbability(double l1, double l2, double P, double k1, double k2)
{
	return (k1 / l1) * P * (k2 / l2);
}