#include <iostream>
#include <string>


#include "utility.h"

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

Triangle* newTriangle(int way) {

	Point points[3];
	switch (way) {
	case DEFAULT:
		return new Triangle;
	case INPUT:
		for (int i = 0; i < 3; ++i) {
			std::cout << "입력 x" << i + 1 << " y" << i + 1 << '\n';
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
			std::cout << "입력 x y r" << '\n';
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
				std::cout << "입력 x" << i + 1 << " y" << i + 1 << '\n';
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
				std::cout << "입력 x" << i + 1 << " y" << i + 1 << '\n';
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

int getOption() {
	std::cout << "할 행동을 선택하시오 Help - 9: ";
	std::string option{};
	std::cin >> option;
	
	if (iswdigit(option[0]))
		return std::stoi(option);
	else
		return NONE;
}

void deleteSpecificShape(std::string shapesType, ShapeManager& sm) {

	if (("선" == shapesType))
		deleteSpecificShapeLoop<Line*>(sm);
	else if (("삼각형" == shapesType))
		deleteSpecificShapeLoop<Triangle*>(sm);
	else if (("사각형" == shapesType))
		deleteSpecificShapeLoop<Rectangle*>(sm);
	else if (("원" == shapesType) )
		deleteSpecificShapeLoop<Circle*>(sm);

}

void loadShapes(std::string fileName, ShapeManager& sm) {
	std::ifstream in{ fileName };

	if (not in)
		return;

	sm.deleteAllShape();

	int input;
	while (in >> input)
		switch (input) {
		case TRIANGLE:
			sm.load(in, new Triangle);
			break;

		case LINE:
			sm.load(in, new Line);
			break;

		case RECTANGLE:
			sm.load(in, new Rectangle);
			break;

		case CIRCLE:
			sm.load(in, new Circle);
			break;

		}
}
