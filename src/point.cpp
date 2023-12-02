// --------------------------
// Point.cpp	Point class definition - cpp는 컴파일하여 obj 또는 lib로 제공한다
//				2차원 좌표 (x,y)
//				cpp의 내용은 컴파일하여 obj 파일로 제공한다
//				(- 다른 사용자에게 구현 소스를 감출 수 있다)
// 
// 2023. 11. 19	by Wulong
// --------------------------
#include "point.h"

Point::Point()
	: x(0.0), y(0.0)
{
};

Point::Point(double a, double b) : x(a), y(b)
{
};