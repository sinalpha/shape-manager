#include <iostream>
#include <string>
#include <fstream>

#include "line.h"

Line::Line()
	: st{}, ed{}
{
}

Line::Line(const Point& p1, const Point& p2) 
	: st{p1}, ed{p2}
{
}

Line::~Line() {
}

std::string Line::save() const {
	return std::to_string(st.x) +
		" " + std::to_string(st.y) +
		" " + std::to_string(ed.x) +
		" " + std::to_string(ed.y);
}

void Line::draw() const {
	std::cout << "¼± - (" << st.x << "," << st.y << "), ("
		<< ed.x << "," << ed.y << ")" << "\n";
}

void Line::load(std::ifstream& in) {
	in >> st.x >> st.y >> ed.x >> ed.y;
}