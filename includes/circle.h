// --------------------------
// Circle.h		�߽����� ��ǥ�� ���������� ���� ������ �� �ִ�.
//				(�ٸ� ������� ���� ������ ���� �ִ�)
// 
// 2023. 11. 19		by Wulong
// --------------------------
#pragma once
#include <string>
#include <fstream>

#include "point.h"
#include "shape.h"

class Circle : public Shape
{
	Point center;			
	double rad;				

public:
	Circle();
	Circle(const Point&, double);
	Circle(const Circle&);	
	
	~Circle();				

	std::string save() const override;
	virtual void draw() const override;
	void load(std::ifstream& in) override;
};