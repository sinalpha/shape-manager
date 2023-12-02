#pragma once
#include <string.h>
#include <fstream>

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "line.h"
#include "shape.h"

enum SHAPE_TYPE {
	NONE = 0,
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

enum ACTION_TYPE {
	CREATE_SHAPE = 1,
	DRAW_SHAPE,
	DELETE_SPEC_SHPAE,
	DELETE_NTH_SHAPE,
	SAVE_SHAPE,
	LOAD_SHAPE
};

const std::string help = "\n0: ���α׷� �����ϱ�\n1 (����) (���� ���) : ���ϴ� ���� �߰�\n2 : ��ü ������ �׸���\n3 : n��° ������ ����\n4 : ���ϴ� ������ ��� ����\n5: �����ϱ�\n6: �ҷ�����\n";
const std::string insertHelp = "1 (����) (���� ���)\n����		: 1 - ��, 2 - ���簢��, 3 - �ﰢ��, 4 - ��\n���� ���	: default - �⺻ ����, 2 - ���� �Է��ؼ� ����\n������ ����µ� �����Ͽ����ϴ�";

Shape* selShape(int, int);
Triangle* newTriangle(int);
Circle* newCircle(int);
Rectangle* newRectangle(int);
Line* newLine(int);
Circle* loadCircle(std::ifstream&);
Rectangle* loadRectangle(std::ifstream&);
Line* loadLine(std::ifstream&);
Triangle* loadTriangle(std::ifstream&);

void printStatus(const std::string&);
void printStatus(const std::string&, int, int);
int getOption();
int stringToInt(const std::string&);