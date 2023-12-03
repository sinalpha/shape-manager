// --------------------------
// Point.cpp	Point class definition - cpp�� �������Ͽ� obj �Ǵ� lib�� �����Ѵ�
//				2���� ��ǥ (x,y)
//				cpp�� ������ �������Ͽ� obj ���Ϸ� �����Ѵ�
//				(- �ٸ� ����ڿ��� ���� �ҽ��� ���� �� �ִ�)
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