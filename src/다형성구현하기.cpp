//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- �������̶� �����ΰ�?
//		- C++���� �������� ��� �����ϴ°�?
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include <iostream>
#include <string.h>

#include "../includes/ShapeManager.h"
#include "utility.h"

// To Do ShapeManger������ ���� shape�� include�ϰ� ��.
int main()
{

	ShapeManager sm(100);

	int option;
	while (0 != (option = getOption())) {
		
		std::string input1, input2{};
		
		switch (option) {
		case CREATE_SHAPE:
			std::cout << "(����) (���� ���): ";
			std::cin >> input1 >> input2;
			if (!checkIsDigit(input1 + input2)) {
				std::cout << insertHelp;
				continue;
			}
			sm.action(CREATE_SHAPE, input1, selShape(input1[0] - '0', input2[0] - '0'));
			break;
		case DRAW_SHAPE:
			sm.action(DRAW_SHAPE, input1, nullptr);
			break;
		case DELETE_SPEC_SHPAE:
			std::cout << "� ������ ����ڽ��ϱ�?: ";
			std::cin >> input1;
			sm.action(DELETE_SPEC_SHPAE, input1, nullptr);
			break;
		case DELETE_NTH_SHAPE:
			std::cout << "���� ������ ��ġ : ";
			std::cin >> input1;
			if (!checkIsDigit(input1))
				continue;
			sm.action(DELETE_NTH_SHAPE, input1, nullptr);
			break;
		case SAVE_SHAPE:
			std::cout << "������ ������ ��ġ�� �Է��Ͻÿ�: ";
			std::cin >> input1;
			sm.action(SAVE_SHAPE, input1, nullptr);
			break;
		case LOAD_SHAPE:
			std::cout << "�ε��� ������ �Է��Ͻÿ�: ";
			std::cin >> input1;
			sm.action(LOAD_SHAPE, input1, nullptr);
			break;
		default:
			std::cout << help;
		}
			
	}
		

		
}


