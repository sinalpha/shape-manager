// --------------------------
// ShapeManger.cpp	도형을 관리하는 클래스
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include <fstream>
#include <string>

#include "shapeManager.h"

using namespace std;

ShapeManager::ShapeManager(int n)
{
	printStatus("관리를 시작합니다"s);

	nShape = 0;			
	capacity = n;
	shapes = new Shape*[capacity];
}
ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;

	printStatus("관리를 종료합니다"s);
}
bool ShapeManager::action(int option, const string& input1, Shape* shape) {

	switch (option) {
	case CREATE_SHAPE:
		insert(shape);
		return true;
	case DRAW_SHAPE:
		draw();
		return true;
	case DELETE_SPEC_SHPAE:
		deleteSpecificShape(input1);
		return true;
	case DELETE_NTH_SHAPE:
		deleteNthShape(stoi(input1));
		return true;
	case SAVE_SHAPE:
		save(input1);
		return true;
	case LOAD_SHAPE:
		load(input1);
		return true;
	default:
		return false;
	}

}

void ShapeManager::insert(Shape* a)
{

	printStatus("도형을 만듭니다");

	if (nullptr == a) {
		printStatus("도형을 만드는데 실패하였습니다");
		return;
	}

	if (nShape == capacity)
		increaseCapacity();
	
	shapes[nShape] = a;
	++nShape;
	printStatus("생성 후 결과", capacity, nShape);

	printStatus("도형을 만드는데 성공하였습니다"s);

}
void ShapeManager::draw() const
{

	printStatus("관리하는 모든 도형을 그립니다"s, capacity, nShape);

	if (nShape <= 0)
		printStatus("그릴 도형이 없습니다"s);

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();
	}

	printStatus("그리기를 마칩니다"s);

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

	printStatus("모든 도형을 "s + fileName + "에 저장합니다"s);

	ofstream out{ fileName };
	for (int i = 0; i < nShape; ++i)
		out << to_string(ConvertShapeTypeToInt(getShapeType(shapes[i]))) + " " + shapes[i]->save() + " ";

	printStatus("모든 도형을 "s + fileName + "에 저장을 하였습니다"s);

}
void ShapeManager::load(const string& fileName) {

	printStatus(fileName + "에서 읽기를 시작합니다"s);

	ifstream in{ fileName };
	if (not in) {
		printStatus(fileName + "가 존재하지 않습니다"s);
		return;
	}

	int shape_type;
	Shape* newShape;
	while (in >> shape_type) {
		switch (shape_type) {
		case TRIANGLE:
			newShape = new Triangle;
			in >> *newShape;
			insert(newShape);
			continue;
		case CIRCLE:
			newShape = new Circle;
			in >> *newShape;
			insert(newShape);
			continue;
		case LINE:
			newShape = new Line;
			in >> *newShape;
			insert(newShape);
			continue;
		case RECTANGLE:
			newShape = new Rectangle;
			in >> *newShape;
			insert(newShape);
			continue;
		default:
			printStatus("읽기를 실패하였습니다");
			return;
		}
	}

	printStatus("읽기를 성공적으로 마쳤습니다");

}



string ShapeManager::getShapeType(Shape* shape) const {
	if (dynamic_cast<Line*>(shape))
		return "선";

	if (dynamic_cast<Circle*>(shape))
		return "원";

	if (dynamic_cast<Rectangle*>(shape))
		return "사각형";

	if (dynamic_cast<Triangle*>(shape))
		return "삼각형";

	return "None";
}

int ShapeManager::ConvertShapeTypeToInt(const string& str) const {
	if ("삼각형" == str)
		return TRIANGLE;
	if ("사각형" == str)
		return RECTANGLE;
	if ("원" == str)
		return CIRCLE;
	if ("선" == str)
		return LINE;

	return -1;
}


void ShapeManager::printStatus(const std::string& status) const {
	std::cout << "--------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "--------------------------------------" << '\n';
}

void ShapeManager::printStatus(const std::string& status, int capacity, int nShape) const {
	std::cout << "---------------------------------------" << '\n';
	std::cout << status << '\n';
	std::cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << '\n';
	std::cout << "모두 " << nShape << "개의 도형이 있습니다" << '\n';
	std::cout << "---------------------------------------" << '\n';
}
