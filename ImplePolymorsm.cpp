//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- 다형성이란 무엇인가?
//		- C++에서 다형성을 어떻게 구현하는가?
//
//
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include <iostream>

#include "ShapeManager.h"
#include "utility.h"

int main()
{

	ShapeManager sm(100);

	printStatus("프로그램을 시작합니다");

	int option;
	while (0 != (option = getOption()))
		if (not sm.action(option)) {
			std::cout << "0: 프로그램 종료하기\n";
			std::cout << "1 (도형) (생성 방법): 원하는 도형 추가\n";
			std::cout << "2: 전체 도형을 그리기\n";
			std::cout << "3: n번째 도형을 제거\n";
			std::cout << "4: 원하는 도형을 모두 제거\n";
		}

	printStatus("프로그램을 종료합니다");

}


