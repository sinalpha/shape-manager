// --------------------------
// ShapeManger.cpp	The class managing several Shapes
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include "shapeManager.h"
#include "utility.h"

using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;			
	capacity = n;
	shapes = new Shape * [capacity];
}

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;
}



bool ShapeManager::action() {

	switch (getOption("할 행동을 선택하시오 Help:0: ")){
	case 1: insert(selShape());
		break;
	case 2: draw();
		break;
	case 3: deleteSpecificShape();
		break;
	case 4: deleteNthShape();
		break;
	case 5:
		return false;
	default:
		cout << "1: 원하는 도형 추가\n";
		cout << "2: 전체 도형을 그리기\n";
		cout << "3: n번째 도형을 제거\n";
		cout << "4: 원하는 도형을 모두 제거\n";
		cout << "5: 프로그램 종료하기\n";
	}

	return true;
}

Shape* ShapeManager::selShape() {

	switch (getOption("추가할 도형을 선택하시오: ")) {
	case 1:
		return newCircle();
	case 2:
		return newRectangle();
	case 3:
		return newTriangle();
	case 4:
		return newLine();
	default:
		cout << "1 - Circle\n";
		cout << "2 - Rectangle\n";
		cout << "3 - Triangle\n";
		cout << "4 - Line\n";
		return nullptr;
	}
	
} 
Triangle* ShapeManager::newTriangle() {
	while (true) {
		Point points[3];
		switch (getOption("생성할 방법을 선택하시오: ")) {
		case 1:
			return new Triangle;
		case 2:
			//점 3개 얻기
			for (int i = 0; i < 3; ++i) {
				cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				cin >> points[i].x >> points[i].y;
			}
			return new Triangle(points[0], points[1], points[2]);
		default:
			cout << "1 - 디폴트 생성\n";
			cout << "2 - 점으로 생성\n";
		}
	}
}

Circle* ShapeManager::newCircle() {
	
	while (true) {
		Point point;
		double r;
		switch (getOption("생성할 방법을 선택하시오: ")) {
		case 1:
			return new Circle;
		case 2:
			cout << "input x, y, r" <<  '\n';
			cin >> point.x >> point.y >> r;
			return new Circle(point, r);
		default:
			cout << "1 - 디폴트 생성\n";
			cout << "2 - 점으로 생성\n";
		}
	}
}

Rectangle* ShapeManager::newRectangle() {
	
	while (true) {
		Point points[2];
		switch (getOption("생성할 방법을 선택하시오: ")) {
		case 1:
			return new Rectangle;
		case 2:
			for (int i = 0; i < 2; ++i) {
				cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				cin >> points[i].x >> points[i].y;
			}
			return new Rectangle(points[0], points[1]);
		default:
			cout << "1 - 디폴트 생성\n";
			cout << "2 - 점으로 생성\n";
		}
	}
}

Line* ShapeManager::newLine() {
	while (true) {
		Point points[2];
		switch (getOption("생성할 방법을 선택하시오: ")) {
		case 1:
			return new Line;
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Line(points[0], points[1]);
		default:
			std::cout << "1 - 디폴트 생성\n";
			std::cout << "2 - 점으로 생성\n";
		}
	}
}

void ShapeManager::insert(Shape* a)
{

	cout << "-----------------------" << '\n';
	cout << "도형을 만듭니다." << '\n';
	cout << "-----------------------" << "\n\n";
	if (a == nullptr) {
		cout << "----------------------" << '\n';
		cout << "도형을 만드는데 실패하였습니다.\n";
		cout << "----------------------" << "\n\n";
		return;
	}

	if (nShape == capacity) {
		capacity = capacity + 1;

		shapes = new Shape * [capacity];
	}
	
	shapes[nShape] = a;
	nShape++;
	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape << "\n\n";
		
	cout << "----------------------" << '\n';
	cout << "도형을 만드는데 성공하였습니다.\n";
	cout << "----------------------" << "\n\n";
}

void ShapeManager::draw() const
{
	cout << "-----------------------" << '\n';
	cout << "모든 도형을 그립니다." << '\n';
	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape <<  '\n';
	cout << "-----------------------" << "\n\n";

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "----------------------" << '\n';
	cout << "그리기를 마칩니다." << '\n';
	cout << "----------------------" << "\n\n";
}

void ShapeManager::deleteSpecificShape() {
	cout << "구현 안 함\n";
}

void ShapeManager::deleteNthShape() {
	cout << "구현 안 함\n";
}