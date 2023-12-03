// --------------------------
// Point.h		Point class declaration - 헤더 파일은 언제나 공개되어야 한다.
//				2차원 좌표 (x,y)를 나타낸다
// 
// 2023. 11. 19	by Wulong
// --------------------------
#pragma once	

struct Point
{
	double x, y;

	Point();
	Point(double, double);
	Point(const Point&) = default;
};