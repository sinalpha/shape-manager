// --------------------------
// Rectangle.h		�밢���� �ִ� �� 2���� �簢���� ������ �� �ִ�.
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <string>

#include "point.h"
#include "shape.h"

class Rectangle : public Shape
{
	Point p1, p2;

public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	std::string save() const override;
	virtual void draw() const override;
	
};