// --------------------------
// Rectangle.cpp	대각선에 있는 점 2개로 사각형을 정의할 수 있다.
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include <string>
#include "utility.h"
#include "rectangle.h"

Rectangle::Rectangle()
	: p1(), p2(), Shape{ "Rectangle" }
{
};

Rectangle::Rectangle(const Point& a, const Point& b)
	: p1(a), p2(b), Shape{ "Rectangle" }
{
};

Rectangle::Rectangle(const Rectangle& other)
	: p1(other.p1), p2(other.p2)
{
}

Rectangle::~Rectangle()
{
}

std::string Rectangle::save() const {
	return std::to_string(RECTANGLE) +
		" " + std::to_string(p1.x) +
		" " + std::to_string(p1.y) +
		" " + std::to_string(p2.x) +
		" " + std::to_string(p2.y);
}


void Rectangle::draw() const
{
	std::cout << "Rectangle - (" << p1.x << "," << p1.y << "), ("
		<< p2.x << "," << p2.y << ")" << "\n";
};