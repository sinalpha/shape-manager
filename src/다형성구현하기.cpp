//---------------------------------------------
// ImpleVirtual.cpp
// To Do
//		- �������̶� �����ΰ�?
//		- C++���� �������� ��� �����ϴ°�?
// 2023. 11. 19.	by Wulong
//----------------------------------------------
#include "ShapeManager.h"
#include "utility.h"


// To Do �Է¹��� ���� ��� �˻��ϴ� �Լ� �����
int main()
{

	ShapeManager sm(100);

	int option;
	while (END != (option = getOption()))
		if (not sm.action(option))
			printStatus(help);
}


