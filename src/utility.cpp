#include <iostream>
#include <string>

#include "utility.h"
#include "../includes/ShapeManager.h"



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
	case DEFAULT:
		return new Triangle;
	case INPUT:
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
		case DEFAULT:
			return new Circle;
		case INPUT:
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
		case DEFAULT:
			return new Rectangle;
		case INPUT:
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
		case DEFAULT:
			return new Line;
		case INPUT:
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

bool checkIsDigit(const std::string& str) {

	for (int i = 0; i < str.size(); ++i)
		if (!iswdigit(str[i]))
			return false;

	return true;
}

bool checkIsAlpha(const std::string& str) {
	
	for (int i = 0; i < str.size(); ++i)
		if (!iswalpha(str[i]))
			return false;
	return true;
}

bool checkInput(const std::string& str) {
	
	if (checkIsAlpha(str) and checkIsDigit(str))
		return false;

	return true;
}

int getOption() {
	std::cout << "�� �ൿ�� �����Ͻÿ� Help - 9: ";
	std::string option{};
	std::cin >> option;
	
	if (iswdigit(option[0]))
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