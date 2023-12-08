#include <iostream>
#include <string>


#include "utility.h"

// 안녕하세요

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
// To Do 지정해서 생성을 더 깔끔하게 만들기
Triangle* newTriangle(int way) {

	Point points[3];
	switch (way) {
	case DEFAULT:
		return new Triangle;
	case INPUT:
		//점 3개 얻기
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
	std::cout << "할 행동을 선택하시오 Help - 9: ";
	std::string option{};
	std::cin >> option;
	
	if (iswdigit(option[0]))
		return std::stoi(option);
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

void deleteSpecificShape(std::string shapesType, ShapeManager& sm) {

	std::cout << shapesType;

	Shape* shape;
	// 비효율적이지만 그냥 이렇게 합시다
	for (int i = 1; nullptr != (shape = sm.returnNthShape(i)); ++i) {
		if (("선" == shapesType) and dynamic_cast<Line*>(shape))
			sm.deleteNthShape(i--);	
		if (("삼각형" == shapesType) and dynamic_cast<Triangle*>(shape))
			sm.deleteNthShape(i--);
		if (("사각형" == shapesType) and dynamic_cast<Rectangle*>(shape))
			sm.deleteNthShape(i--);
		if (("원" == shapesType) and dynamic_cast<Circle*>(shape))
			sm.deleteNthShape(i--);
	}

}

void loadShapes(std::string fileName, ShapeManager& sm) {
	std::ifstream in{ fileName };

	if (not in)
		return;

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
