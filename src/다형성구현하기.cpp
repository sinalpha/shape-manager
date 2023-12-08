//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- 다형성이란 무엇인가?
//		- C++에서 다형성을 어떻게 구현하는가?
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include <iostream>
#include <string.h>

#include "../includes/ShapeManager.h"
#include "utility.h"

int main()
{

	ShapeManager sm(100);

	int option;
	while (0 != (option = getOption())) {

		std::string input1, input2{};

		switch (option) {
		case CREATE_SHAPE:
			std::cout << "(도형) (생성 방법): ";
			std::cin >> input1 >> input2;
			if (not checkIsDigit(input1 + input2)) {
				std::cout << insertHelp;
				continue;
			}
			if (not sm.insert(selShape(std::stoi(input1), std::stoi(input2))))
				std::cout << insertHelp;
			break;


		case DRAW_SHAPE:
			sm.draw();
			break;


		case DELETE_SPEC_SHPAE:
			std::cout << "어떤 도형을 지우겠습니까?: ";
			std::cin >> input1;
			deleteSpecificShape(input1, sm);
			break;


		case DELETE_NTH_SHAPE:
			std::cout << "지울 도형의 위치 : ";
			std::cin >> input1;
			if (!checkIsDigit(input1))
				continue;
			sm.deleteNthShape(std::stoi(input1));
			break;


		case SAVE_SHAPE:
			std::cout << "저장할 파일의 위치를 입력하시오: ";
			std::cin >> input1;
			sm.save(input1);
			break;


		case LOAD_SHAPE:
			std::cout << "로드할 파일을 입력하시오: ";
			std::cin >> input1;
			loadShapes(input1, sm);
			break;


		default:
			std::cout << help;
		}
	}



}



