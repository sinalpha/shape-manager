#pragma once
#include "shape.h"
#include "point.h"


class Line : public Shape
{
	Point st, ed;

public:
	Line();
	Line(const Point&, const Point&);



	virtual void draw() const override;
};