#include <string>
#include <fstream>
#include "shape.h"
#include "point.h"


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