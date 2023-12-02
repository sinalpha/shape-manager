#pragma once
#include <string.h>

enum SHAPE_TYPE {
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

const std::string help = "0: ���α׷� �����ϱ�\n1 (����) (���� ���) : ���ϴ� ���� �߰�\n2 : ��ü ������ �׸���\n3 : n��° ������ ����\n4 : ���ϴ� ������ ��� ����";

void printStatus(const std::string);
void printStatus(const std::string, int, int);
int getOption();
int stringToint(const std::string);