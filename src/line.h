#include <string>
#include <fstream>
#include "../includes/point.h"						
#include "../includes/shape.h"		


class Line : public Shape
{
	Point st, ed;

public:
	Line();
	Line(const Point&, const Point&);

	~Line();

	std::string save() const override;
	virtual void draw() const override;
	void load(std::ifstream& in) override;
};