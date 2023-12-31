// --------------------------
// Triangle.h		세 점으로 삼각형을 정의할 수 있다 
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <string>
#include <fstream>
#include "point.h"						
#include "../includes/shape.h"						


class Triangle : public Shape
{
	Point p1, p2, p3;

public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	std::string save() const override;
	void draw() const override;	
	void load(std::ifstream& in) override;


};

