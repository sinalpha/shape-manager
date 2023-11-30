// --------------------------
// Circle.h		중심점의 좌표와 반지름으로 원을 정의할 수 있다.
//				(다른 방식으로 원을 정의할 수도 있다)
// 
// 2023. 11. 19		by Wulong
// --------------------------
#pragma once
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
	Point center;			// 중심점의 좌표
	double rad;				// 반지름

public:
	Circle();
	Circle(const Point&, double);
	Circle(const Circle&);	// 깊은 복사를 할 필요가 없다면 프로그래머가 복사생성자를
							// 프로그래밍할 필요는 없다.
							// 만약 어떤 이유로 프로그램해야 한다면 메모리를 이해하고
							// 코딩해야 한다

	
	~Circle();				// 소멸자를 프로그래밍할 필요가 없다는 것을 생각해 보자.

	virtual void draw() const override;
};