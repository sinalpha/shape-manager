#pragma once
#include <string.h>
#include <fstream>

#include "../includes/shapeManager.h"
#include "line.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

enum WAY_TYPE {
	DEFAULT = 1,
	INPUT
};

enum ACTION_TYPE {
	CREATE_SHAPE = 1,
	DRAW_SHAPE,
	DELETE_SPEC_SHPAE,
	DELETE_NTH_SHAPE,
	SAVE_SHAPE,
	LOAD_SHAPE,
};

enum SHAPE_TYPE {
	NONE = 0,
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

const std::string help = "\n0: ���α׷� �����ϱ�\n1 (����) (���� ���) : ���ϴ� ���� �߰�\n2 : ��ü ������ �׸���\n3 : ���ϴ� ������ ��� ����\n4 : n��° ������ ����\n5: �����ϱ�\n6: �ҷ�����\n";
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
void deleteSpecificShape(std::string, ShapeManager&);
void loadShapes(std::string, ShapeManager&);