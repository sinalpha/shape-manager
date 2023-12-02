#include <iostream>

#include "utility.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "line.h"
#include "shape.h"


//���� ���� ���� ��ƿ
Shape* selShape(int shape, int way) {

	switch (shape) {
	case CIRCLE:
		return newCircle(way);
	case RECTANGLE:
		return newRectangle(way);
	case TRIANGLE:
		return newTriangle(way);
	case LINE:
		return newLine(way);
	default:
		return nullptr;
	}

}
// To Do �����ؼ� ������ �� ����ϰ� �����
Triangle* newTriangle(int way) {

	Point points[3];
	switch (way) {
	case 1:
		return new Triangle;
	case 2:
		//�� 3�� ���
		for (int i = 0; i < 3; ++i) {
			std::cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
			std::cin >> points[i].x >> points[i].y;
		}
		return new Triangle(points[0], points[1], points[2]);
	default:
		return nullptr;
	}

}

Circle* newCircle(int way) {

	while (true) {
		Point point;
		double r;
		switch (way) {
		case 1:
			return new Circle;
		case 2:
			std::cout << "�Է� x, y, r" << '\n';
			std::cin >> point.x >> point.y >> r;
			return new Circle(point, r);
		default:
			return nullptr;
		}
	}

}

Rectangle* newRectangle(int way){

	while (true) {
		Point points[2];
		switch (way) {
		case 1:
			return new Rectangle;
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Rectangle(points[0], points[1]);
		default:
			return nullptr;
		}
	}

}

Line* newLine(int way){
	while (true) {
		Point points[2];
		switch (way) {
		case 1:
			return new Line;
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Line(points[0], points[1]);
		default:
			return nullptr;
		}
	}
}

Circle* loadCircle(std::ifstream& in) {
	
	Point p;
	double r;
	in >> p.x >> p.y >> r;

	return new Circle(p, r);
}

Rectangle* loadRectangle(std::ifstream& in) {
	
	Point p[2];
	for (int i = 0; i < 2; ++i)
		in >> p[i].x >> p[i].y;

	return new Rectangle(p[0], p[1]);
}

Line* loadLine(std::ifstream& in) {

	Point p[2];
	for (int i = 0; i < 2; ++i)
		in >> p[i].x >> p[i].y;

	return new Line(p[0], p[1]);
}

Triangle* loadTriangle(std::ifstream& in) {

	Point p[3];
	for (int i = 0; i < 3; ++i)
		in >> p[i].x >> p[i].y;

	return new Triangle(p[0], p[1], p[2]);
}

//
void printStatus(const std::string& status) {
	std::cout << "--------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "--------------------------------------" << '\n';
}

void printStatus(const std::string& status, int capacity, int nShape) {
	std::cout << "---------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << '\n';
	std::cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << '\n';
	std::cout << "---------------------------------------" << '\n';
}

int getOption() {
	std::cout << "�� �ൿ�� �����Ͻÿ� Help - 9: ";
	std::string option{};
	std::cin >> option;

	if (isdigit(option[0]))
		return option[0] - '0';
	else
		return 9;
}

int stringToInt(const std::string& str) {
	if (str == "Triangle")
		return TRIANGLE;
	else if (str == "Circle")
		return CIRCLE;
	else if (str == "Line")
		return LINE;
	else if (str == "Rectangle")
		return RECTANGLE;
	else
		return NONE;
}		
