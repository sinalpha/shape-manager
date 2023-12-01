// --------------------------
// Triangle.h		�� ������ �ﰢ���� ������ �� �ִ� 
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include "point.h"						// Point�� Triangle���� ���
#include "shape.h"						// Shape�� ��� ����

class Triangle : public Shape
{
	Point p1, p2, p3;

public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;	
};

