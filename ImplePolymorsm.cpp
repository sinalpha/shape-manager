//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- �������̶� �����ΰ�?
//		- C++���� �������� ��� �����ϴ°�?
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

	printStatus("���α׷��� �����մϴ�");

	int option;
	while (0 != (option = getOption()))
		if (not sm.action(option)) {
			std::cout << "0: ���α׷� �����ϱ�\n";
			std::cout << "1 (����) (���� ���): ���ϴ� ���� �߰�\n";
			std::cout << "2: ��ü ������ �׸���\n";
			std::cout << "3: n��° ������ ����\n";
			std::cout << "4: ���ϴ� ������ ��� ����\n";
		}

	printStatus("���α׷��� �����մϴ�");

}


