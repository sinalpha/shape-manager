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

// 복사생성자를 프로그래밍할 이유가 있다면 멤버변수의 값을 복사해야한다.
// 복사생성자를 프로그래밍하면서 아무것도 하지 않으면 멤버변수는 복사되지 않는다.

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

