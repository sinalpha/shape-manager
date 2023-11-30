#include <iostream>
#include "line.h"
#include "utility.h"

Line::Line()
	: st{}, ed{}
{
}

Line::Line(const Point& p1, const Point& p2) 
	: st{p1}, ed{p2}
{
}

void* Line::operator new(size_t i) {
	while (true) {
		Point points[2];
		switch (getOption("������ ����� �����Ͻÿ�: ")) {
		case 1:
			return malloc(sizeof Line);
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Line(points[0], points[1]);
		default:
			std::cout << "1 - ����Ʈ ����\n";
			std::cout << "2 - ������ ����\n";
		}
	}
}

void Line::draw() const {
	std::cout << "Line - (" << st.x << "," << st.y << "), ("
		<< ed.x << "," << ed.y << ")" << "\n";
}