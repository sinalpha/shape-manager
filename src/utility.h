#pragma once
#include <string.h>
#include <fstream>

#include "../includes/ShapeManager.h"


enum WAY_TYPE {
	DEFAULT = 1,
	INPUT
};

const std::string help = "\n0: 프로그램 종료하기\n1 (도형) (생성 방법) : 원하는 도형 추가\n2 : 전체 도형을 그리기\n3 : n번째 도형을 제거\n4 : 원하는 도형을 모두 제거\n5: 저장하기\n6: 불러오기\n";
const std::string insertHelp = "1 (도형) (생성 방법)\n도형		: 1 - 원, 2 - 직사각형, 3 - 삼각형, 4 - 선\n생성 방법	: default - 기본 생성, 2 - 값을 입력해서 생성\n도형을 만드는데 실패하였습니다";

Shape* selShape(int, int);
Triangle* newTriangle(int);
Circle* newCircle(int);
Rectangle* newRectangle(int);
Line* newLine(int);

bool checkIsDigit(const std::string&);
bool checkInput(const std::string&);
int getOption();
int stringToInt(const std::string&);
