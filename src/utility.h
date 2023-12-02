#pragma once
#include <string.h>

enum SHAPE_TYPE {
	NONE = 0,
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

const std::string help = "\n0: 프로그램 종료하기\n1 (도형) (생성 방법) : 원하는 도형 추가\n2 : 전체 도형을 그리기\n3 : n번째 도형을 제거\n4 : 원하는 도형을 모두 제거\n5: 저장하기\n6: 불러오기\n";

void printStatus(const std::string);
void printStatus(const std::string, int, int);
int getOption();
int stringToInt(const std::string);