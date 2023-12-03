// --------------------------
// Circle.cpp	
// 
// 2023. 11. 19		by Wulong
// --------------------------

#include <iostream>
#include <fstream>
#include <string>

#include "circle.h"

Circle::Circle()
	: center{}, rad{0.0}
{
}

Circle::Circle(const Point& c, double r)
	: center{ c }, rad{ r }
{
}

Circle::Circle(const Circle& other)
	: center{ other.center }, rad{ other.rad }
{
}

Circle::~Circle()
{
}

std::string Circle::save() const
{
	return "1 " +
		std::to_string(center.x) + " " +
		std::to_string(center.y) + " " +
		std::to_string(rad);
}

void Circle::draw() const
{
	std::cout << "원 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
}

void Circle::load(std::ifstream& in) {
	in >> center.x >> center.y >> rad;

}
