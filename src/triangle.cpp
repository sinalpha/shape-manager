// --------------------------
// Triangle.cpp
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>	
#include <string>
#include "triangle.h"
#include "utility.h"

Triangle::Triangle()
	: p1{}, p2{}, p3{}, Shape{"Triangle"}
{
};

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1{a}, p2{b}, p3{c}, Shape{"Triangle"}
{
};

Triangle::Triangle(const Triangle& other)
	: p1{ other.p1 }, p2{ other.p2 }, p3{ other.p3 }, Shape{ "Triangle" }
{
}

Triangle::~Triangle()
{
	std::cout << "del" << '\n';
}

std::string Triangle::save() const {
	return std::to_string(TRIANGLE) +
		" " + std::to_string(p1.x) +
		" " + std::to_string(p1.y) +
		" " + std::to_string(p2.x) +
		" " + std::to_string(p2.y) +
		" " + std::to_string(p3.x) +
		" " + std::to_string(p3.y);
}

void Triangle::draw() const
{
	std::cout << "Triangle - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << "), ("
		<< p3.x << "," << p3.y << ")" << "\n";
}