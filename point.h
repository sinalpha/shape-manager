// --------------------------
// Point.h		Point class declaration - ��� ������ ������ �����Ǿ�� �Ѵ�.
//				2���� ��ǥ (x,y)�� ��Ÿ����
// 
// 2023. 11. 19	by Wulong
// --------------------------
#pragma once	// ���࿡ vs 2022������ �������Ѵٰ� �ϸ��� #pragma once�� #ifndef _Point ... #endif�� ������ ���� ���ΰ�?

struct Point
{
	double x, y;

	Point();
	Point(double, double);
	Point(const Point&) = default;
};