#include <iostream>
#include <string>
#include "circle.h"
#include "utility.h"

Circle::Circle()
	: center(), rad(0.0), Shape{ "��" }
{
}

Circle::Circle(const Point& c, double r)
	: center(c), rad(r), Shape{"��"}
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
}

std::string Circle::save() const
{
	return std::to_string(CIRCLE) +
		" " + std::to_string(center.x) +
		" " + std::to_string(center.y) +
		" " + std::to_string(rad);
}

void Circle::draw() const
{
	std::cout << "�� - �߽���(" << center.x << "," << center.y
		<< ") ������ " << rad << '\n';
}

