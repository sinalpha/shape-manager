// --------------------------
// Circle.h		중심점의 좌표와 반지름으로 원을 정의할 수 있다.
//				(다른 방식으로 원을 정의할 수도 있다)
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <string>
#include <fstream>

#include "point.h"						
#include "../includes/shape.h"		

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
	void draw() const override;
	void load(std::ifstream& in) override;
};