#include <iostream>
#include "line.h"

Line::Line()
	: st{}, ed{}
{
}

Line::Line(const Point& p1, const Point& p2) 
	: st{p1}, ed{p2}
{
}



void Line::draw() const {
	std::cout << "Line - (" << st.x << "," << st.y << "), ("
		<< ed.x << "," << ed.y << ")" << "\n";
}