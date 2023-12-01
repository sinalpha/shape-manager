//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- 다형성이란 무엇인가?
//		- C++에서 다형성을 어떻게 구현하는가?
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


