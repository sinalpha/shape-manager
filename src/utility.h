#pragma once
#include <string.h>

enum SHAPE_TYPE {
	NONE = 0,
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

const std::string help = "\n0: ���α׷� �����ϱ�\n1 (����) (���� ���) : ���ϴ� ���� �߰�\n2 : ��ü ������ �׸���\n3 : n��° ������ ����\n4 : ���ϴ� ������ ��� ����\n5: �����ϱ�\n6: �ҷ�����\n";

void printStatus(const std::string);
void printStatus(const std::string, int, int);
int getOption();
int stringToInt(const std::string);