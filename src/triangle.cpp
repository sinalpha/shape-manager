// --------------------------
// Triangle.cpp
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>	
#include <string>
#include <fstream>
#include "triangle.h"


Triangle::Triangle()
	: p1{}, p2{}, p3{}
{
};

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1{a}, p2{b}, p3{c}
{
};

Triangle::Triangle(const Triangle& other)
	: p1{ other.p1 }, p2{ other.p2 }, p3{ other.p3 }
{
}

Triangle::~Triangle()
{
}

std::string Triangle::save() const {
	return   "3 " +
		std::to_string(p1.x) + " " + 
		std::to_string(p1.y) + " " + 
		std::to_string(p2.x) + " " +
		std::to_string(p2.y) + " " + 
		std::to_string(p3.x) + " " +
		std::to_string(p3.y);
}

void Triangle::draw() const
{
	std::cout << "�ﰢ�� - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), ("
		<< p3.x << "," << p3.y << ")" << "\n";
}

void Triangle::load(std::ifstream& in) {

	in >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

}