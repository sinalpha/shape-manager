// --------------------------
// Rectangle.cpp	�밢���� �ִ� �� 2���� �簢���� ������ �� �ִ�.
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include <string>
#include "rectangle.h"

Rectangle::Rectangle()
	: p1{}, p2{}
{
};

Rectangle::Rectangle(const Point& a, const Point& b)
	: p1{a}, p2{b}
{
};

Rectangle::Rectangle(const Rectangle& other)
	: p1{other.p1}, p2{other.p2}
{
}

Rectangle::~Rectangle()
{
}

std::string Rectangle::save() const {
	return "2 " +
		std::to_string(p1.x) + " " +
		std::to_string(p1.y) + " " +
		std::to_string(p2.x) + " " +
		std::to_string(p2.y);
}


void Rectangle::draw() const
{
	std::cout << "�簢�� - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << "\n";
};

void Rectangle::load(std::ifstream& in) {


	in >> p1.x >> p1.y >> p2.x >> p2.y;


}