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
	NONE = 9
};

enum SHAPE_TYPE {
	CIRCLE = 1,
	RECTANGLE,
	TRIANGLE,
	LINE
};

const std::string help = "\n0: 프로그램 종료하기\n1 (도형) (생성 방법) : 원하는 도형 추가\n2 : 전체 도형을 그리기\n3 : 원하는 도형을 모두 제거\n4 : n번째 도형을 제거\n5: 저장하기\n6: 불러오기\n";
const std::string insertHelp = "1 (도형) (생성 방법)\n도형		: 1 - 원, 2 - 직사각형, 3 - 삼각형, 4 - 선\n생성 방법	: default - 기본 생성, 2 - 값을 입력해서 생성\n도형을 만드는데 실패하였습니다";

Shape* selShape(int, int);
Triangle* newTriangle(int);
Circle* newCircle(int);
Rectangle* newRectangle(int);
Line* newLine(int);
bool checkIsDigit(const std::string&);
int getOption();
void deleteSpecificShapeLoop(ShapeManager&);
void deleteSpecificShape(std::string, ShapeManager&);
void loadShapes(std::string, ShapeManager&);

template <typename T>
void deleteSpecificShapeLoop(ShapeManager& sm) {


	Shape* shape;

	for (int i = 1; nullptr != (shape = sm.returnNthShape(i)); ++i)
		if (dynamic_cast<T>(shape)) {
			sm.deleteNthShape(i--);
		}
			

}