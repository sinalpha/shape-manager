#include <iostream>

#include "utility.h"

void printStatus(std::string status) {
	std::cout << "----------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "----------------------" << '\n';
}

void printStatus(std::string status, int capacity, int nShape) {
	std::cout << "-----------------------" << '\n';
	std::cout << "��� ������ �׸��ϴ�." << '\n';
	std::cout << "Capacitiy: " << capacity << '\n';
	std::cout << "NUM: " << nShape << '\n';
	std::cout << "-----------------------" << '\n';
}

int getOption() {
	std::cout << "�� �ൿ�� �����Ͻÿ� Help - 5: ";
	std::string option{};
	std::cin >> option;

	if (isdigit(option[0]))
		return option[0] - '0';
	else
		return 5;
}
