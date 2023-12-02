#include <iostream>
#include <string>

#include "utility.h"
#include "line.h"

Line::Line()
	: st{}, ed{}, Shape{ "Line" }
{
}

Line::Line(const Point& p1, const Point& p2) 
	: st{p1}, ed{p2}, Shape{"Line"}
{
}

std::string Line::save() const {
	return std::to_string(LINE) +
		" " + std::to_string(st.x) +
		" " + std::to_string(st.y) +
		" " + std::to_string(ed.x) +
		" " + std::to_string(ed.y);
}

void Line::draw() const {
	std::cout << "Line - (" << st.x << "," << st.y << "), ("
		<< ed.x << "," << ed.y << ")" << "\n";
}