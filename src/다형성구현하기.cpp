//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- �������̶� �����ΰ�?
//		- C++���� �������� ��� �����ϴ°�?
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include <iostream>

#include "ShapeManager.h"
#include "utility.h"

int main()
{
	ShapeManager sm(1);

	

	int option;
	while (0 != (option = getOption()))
		if (not sm.action(option))
			printStatus(help);
	

	

}


