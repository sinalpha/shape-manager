#pragma once
#include <string.h>
#include <fstream>

#include "../includes/ShapeManager.h"


enum WAY_TYPE {
	DEFAULT = 1,
	INPUT
};

const std::string help = "\n0: ���α׷� �����ϱ�\n1 (����) (���� ���) : ���ϴ� ���� �߰�\n2 : ��ü ������ �׸���\n3 : n��° ������ ����\n4 : ���ϴ� ������ ��� ����\n5: �����ϱ�\n6: �ҷ�����\n";
const std::string insertHelp = "1 (����) (���� ���)\n����		: 1 - ��, 2 - ���簢��, 3 - �ﰢ��, 4 - ��\n���� ���	: default - �⺻ ����, 2 - ���� �Է��ؼ� ����\n������ ����µ� �����Ͽ����ϴ�";

Shape* selShape(int, int);
Triangle* newTriangle(int);
Circle* newCircle(int);
Rectangle* newRectangle(int);
Line* newLine(int);

bool checkIsDigit(const std::string&);
bool checkInput(const std::string&);
int getOption();
int stringToInt(const std::string&);
