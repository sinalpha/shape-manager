//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- 다형성이란 무엇인가?
//		- C++에서 다형성을 어떻게 구현하는가?
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include <iostream>
#include <string.h>

#include "ShapeManager.h"
#include "utility.h"

// To Do 사람이 쓰는 프로그램이 아닌 프레임워크처럼 만들기
// To Do 입력받은 값을 모두 검사하는 함수 만들기
int main()
{

	ShapeManager sm(100);

	int option;
	while (END != (option = getOption())) {
		
		std::string input1, input2{};
		
		switch (option) {
		case CREATE_SHAPE:
			std::cout << "(도형) (생성 방법): ";
			std::cin >> input1 >> input2;
			if (!checkIsDigit(input1 + input2)) {
				printStatus(insertHelp);
				continue;
			}
			sm.action(CREATE_SHAPE, input1, selShape(input1[0] - '0', input2[0] - '0'));
			break;
		case DRAW_SHAPE:
			sm.action(DRAW_SHAPE, input1, nullptr);
			break;
		case DELETE_SPEC_SHPAE:
			std::cout << "어떤 도형을 지우겠습니까?: ";
			std::cin >> input1;
			sm.action(DELETE_SPEC_SHPAE, input1, nullptr);
			break;
		case DELETE_NTH_SHAPE:
			std::cout << "지울 도형의 위치 : ";
			std::cin >> input1;
			if (!checkIsDigit(input1))
				continue;
			sm.action(DELETE_NTH_SHAPE, input1, nullptr);
			break;
		case SAVE_SHAPE:
			std::cout << "저장할 파일의 위치를 입력하시오: ";
			std::cin >> input1;
			sm.action(SAVE_SHAPE, input1, nullptr);
			break;
		case LOAD_SHAPE:
			std::cout << "로드할 파일을 입력하시오: ";
			std::cin >> input1;
			sm.action(LOAD_SHAPE, input1, nullptr);
			break;
		default:
			printStatus(help);
		}
			
	}
		

		
}


