// --------------------------
// Circle.h		�߽����� ��ǥ�� ���������� ���� ������ �� �ִ�.
//				(�ٸ� ������� ���� ������ ���� �ִ�)
// 
// 2023. 11. 19		by Wulong
// --------------------------
#pragma once
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
	Point center;			// �߽����� ��ǥ
	double rad;				// ������

public:
	Circle();
	Circle(const Point&, double);
	Circle(const Circle&);	// ���� ���縦 �� �ʿ䰡 ���ٸ� ���α׷��Ӱ� ��������ڸ�
							// ���α׷����� �ʿ�� ����.
							// ���� � ������ ���α׷��ؾ� �Ѵٸ� �޸𸮸� �����ϰ�
							// �ڵ��ؾ� �Ѵ�

	
	~Circle();				// �Ҹ��ڸ� ���α׷����� �ʿ䰡 ���ٴ� ���� ������ ����.

	virtual void draw() const override;
};