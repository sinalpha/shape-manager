// --------------------------
// Point.h		Point class declaration - ��� ������ ������ �����Ǿ�� �Ѵ�.
//				2���� ��ǥ (x,y)�� ��Ÿ����
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