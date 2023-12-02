// --------------------------
// ShapeManger.cpp	도형을 관리하는 클래스
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include <fstream>
#include <string>

#include "shapeManager.h"
#include "utility.h"

using namespace std;

ShapeManager::ShapeManager(int n)
{
	for (int i = 0; i < 10; ++i)
		cout << "무작위로 입력하지 마세요 ㅡㅡ;(필수 기능만 구현함)\n";

	printStatus("관리를 시작합니다");

	nShape = 0;			
	capacity = n;
	shapes = new Shape*[capacity];
}
ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;

	printStatus("관리를 종료합니다");
}
bool ShapeManager::action(int option) {

	string input1, input2{};

	switch (option) {
	case CREATE_SHAPE:
		cout << "(도형) (생성 방법): ";
		cin >> input1 >> input2;
		insert(selShape(input1[0] - '0', input2[0] - '0'));
		return true;
	case DRAW_SHAPE:
		draw();
		return true;
	case DELETE_SPEC_SHPAE:
		cout << "어떤 도형을 지우겠습니까?: ";
		cin >> input1;
		deleteSpecificShape(input1);
		return true;
	case DELETE_NTH_SHAPE:
		cout << "현재 관리하고 있는 도형 - " << nShape << " 지울 도형의 위치: ";
		cin >> input1;
		deleteNthShape(stoi(input1));
		return true;
	case SAVE_SHAPE:
		cout << "저장할 파일의 위치를 입력하시오: ";
		cin >> input1;
		save(input1);
		return true;
	case LOAD_SHAPE:
		cout << "로드할 파일을 입력하시오: ";
		cin >> input1;
		load(input1);
		return true;
	default:
		return false;
	}

}


void ShapeManager::insert(Shape* a)
{

	printStatus(a->shapeType + " 도형을 만듭니다");


	if (nullptr == a) {
		printStatus(insertHelp);
		return;
	}

	if (nShape == capacity)
		increaseCapacity();
	shapes[nShape] = a;
	++nShape;
	printStatus("생성 후 결과", capacity, nShape);

	printStatus(a->shapeType + " 도형을 만드는데 성공하였습니다"s);

}
void ShapeManager::draw() const
{

	printStatus("관리하는 모든 도형을 그립니다", capacity, nShape);

	if (nShape <= 0)
		printStatus("그릴 도형이 없습니다");

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();
	}

	printStatus("그리기를 마칩니다");

}
void ShapeManager::deleteSpecificShape(const string& type) {

	printStatus(type + "을 모두 지웁니다");

	// To Do O(n)으로 지우기
	for (int i = 0; i < nShape; ++i) {
		if (type == "삼각형")
			if (dynamic_cast<Triangle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "원")
			if (dynamic_cast<Circle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "사각형")
			if (dynamic_cast<Rectangle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "선")
			if (dynamic_cast<Line*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
	}

	printStatus(type + "을 모두 지웠습니다");

}
void ShapeManager::deleteNthShape(int n) {

	printStatus(to_string(n) + "번째 도형을 지웁니다"s);

	if (0 >= n or nShape < n) {
		printStatus("잘못된 숫자를 입력하였습니다", capacity, nShape);
		return;
	}

	int idx = n - 1;
	delete shapes[idx];
	// To Do memcpy로 개선가능
	for (int i = idx; i < nShape - 1; ++i)
		shapes[i] = shapes[i + 1];
	--nShape;

	printStatus(to_string(n) + "번째 도형을 지웠습니다"s);

}
void ShapeManager::increaseCapacity() {

	printStatus("수용 용량을 늘립니다.");

	Shape** temp = shapes;
	capacity = capacity * 2;
	shapes = new Shape * [capacity];
	memcpy(shapes, temp, sizeof(Shape*) * nShape);
	delete[] temp;

}
void ShapeManager::save(const string& fileName) const {

	printStatus("모든 도형을 " + fileName + "에 저장합니다");

	ofstream out{ fileName };
	for (int i = 0; i < nShape; ++i)
		out << shapes[i]->save() + " ";

	printStatus("모든 도형을 " + fileName + "에 저장을 하였습니다");

}
void ShapeManager::load(const string& fileName) {

	printStatus(fileName + "에서 읽기를 시작합니다");

	ifstream in{ fileName };
	if (not in) {
		printStatus(fileName + "가 존재하지 않습니다");
		return;
	}

	int shape_type;

	while (in >> shape_type) {
		switch (shape_type) {
		case TRIANGLE:
			insert(loadCircle(in));
			continue;
		case CIRCLE:
			insert(loadCircle(in));
			continue;
		case LINE:
			insert(loadLine(in));
			continue;
		case RECTANGLE:
			insert(loadRectangle(in));
			continue;
		default:
			printStatus("읽기를 실패하였습니다");
			return;
		}
	}

	printStatus("읽기를 성공적으로 마쳤습니다");

}



