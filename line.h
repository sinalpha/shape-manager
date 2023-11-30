#pragma once
#include "shape.h"
#include "point.h"


class Line : public Shape
{
	Point st, ed;

public:
	Line();
	Line(const Point&, const Point&);

	void* operator new(size_t i);

	virtual void draw() const override;
};