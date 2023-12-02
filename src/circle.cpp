#include <iostream>
#include <string>
#include "circle.h"
#include "utility.h"

Circle::Circle()
	: center(), rad(0.0), Shape{ "원" }
{
}

Circle::Circle(const Point& c, double r)
	: center(c), rad(r), Shape{"원"}
{
}

// 복사생성자를 프로그래밍할 이유가 있다면 멤버변수의 값을 복사해야한다.
// 복사생성자를 프로그래밍하면서 아무것도 하지 않으면 멤버변수는 복사되지 않는다.

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
	std::cout << "원 - 중심점(" << center.x << "," << center.y
		<< ") 반지름 " << rad << '\n';
}

