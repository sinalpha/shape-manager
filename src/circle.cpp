#include <iostream>
#include "circle.h"

Circle::Circle()
	: center(), rad(0.0), Shape{ "Circle" }
{
}

Circle::Circle(const Point& c, double r)
	: center(c), rad(r), Shape{"Circle"}
{
}

// ��������ڸ� ���α׷����� ������ �ִٸ� ��������� ���� �����ؾ��Ѵ�.
// ��������ڸ� ���α׷����ϸ鼭 �ƹ��͵� ���� ������ ��������� ������� �ʴ´�.

Circle::Circle(const Circle& other)
	: center(other.center), rad(other.rad)
{
}

Circle::~Circle()
{
	std::cout << "del" << '\n';
}

void Circle::draw() const
{
	std::cout << "Circle - center(" << center.x << "," << center.y
		<< ") radius " << rad << '\n';
}

