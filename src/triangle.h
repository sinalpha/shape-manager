// --------------------------
// Triangle.h		�� ������ �ﰢ���� ������ �� �ִ� 
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <string>
#include <fstream>
#include "point.h"						
#include "shape.h"						


class Triangle : public Shape
{
	Point p1, p2, p3;

public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	std::string save() const override;
	virtual void draw() const override;	
	void load(std::ifstream& in) override;


};
