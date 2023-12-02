#include <iostream>

#include "utility.h"

void printStatus(const std::string status) {
	std::cout << "--------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "--------------------------------------" << '\n';
}

void printStatus(const std::string status, int capacity, int nShape) {
	std::cout << "---------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "Capacitiy: " << capacity << '\n';
	std::cout << "NUM: " << nShape << '\n';
	std::cout << "---------------------------------------" << '\n';
}

int getOption() {
	std::cout << "할 행동을 선택하시오 Help - 9: ";
	std::string option{};
	std::cin >> option;

	if (isdigit(option[0]))
		return option[0] - '0';
	else
		return 9;
}

int stringToInt(const std::string str) {
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
