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
	case 1:
		cout << "(도형) (생성 방법): ";
		cin >> input1 >> input2;
		insert(selShape(input1[0] - '0', input2[0] - '0'));
		return true;
	case 2: draw();
		return true;
	case 3: deleteSpecificShape();
		return true;
	case 4:
		cout << "현재 NUM - " << nShape << "";
		cin >> input1;
		deleteNthShape(input1[0] - '0');
		return true;
	default:
		return false;
	}
}

Shape* ShapeManager::selShape(int shape,int way) {
	switch (shape) {
	case 1:
		return newCircle(way);
	case 2:
		return newRectangle(way);
	case 3:
		return newTriangle(way);
	case 4:	
		return newLine(way);
	default: 
		return nullptr;
	}
	
} 
Triangle* ShapeManager::newTriangle(int way) {
		Point points[3];
		switch (way) {
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
			return nullptr;
		}
}
Circle* ShapeManager::newCircle(int way) {
	
	while (true) {
		Point point;
		double r;
		switch (way) {
		case 1:
			return new Circle;
		case 2:
			cout << "input x, y, r" <<  '\n';
			cin >> point.x >> point.y >> r;
			return new Circle(point, r);
		default: 
			return nullptr;
		}
	}
}
Rectangle* ShapeManager::newRectangle(int way) {
	
	while (true) {
		Point points[2];
		switch (way) {
		case 1:
			return new Rectangle;
		case 2:
			for (int i = 0; i < 2; ++i) {
				cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				cin >> points[i].x >> points[i].y;
			}
			return new Rectangle(points[0], points[1]);
		default: 
			return nullptr;
		}

	}
}
Line* ShapeManager::newLine(int way) {
	while (true) {
		Point points[2];
		switch (way) {
		case 1:
			return new Line;
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Line(points[0], points[1]);
		default: 
			return nullptr;
		}
	}
}
void ShapeManager::insert(Shape* a)
{

	printStatus("도형을 만듭니다");

	if (nullptr == a) {
		cout << "1 (도형) (생성 방법)\n";
		cout << "도형		: 1 - 원, 2 - 직사각형, 3 - 삼각형, 4 - 선\n";
		cout << "생성 방법	: default - 기본 생성, 2 - 값을 입력해서 생성\n";
		printStatus("도형을 만드는데 실패하였습니다");
		return;
	}

	if (nShape == capacity) {
		printStatus("수용 용량을 늘립니다.");
		Shape** temp = shapes;
		capacity = capacity * 2;
		shapes = new Shape*[capacity];
		memcpy(shapes, temp, sizeof(Shape*) * nShape);
		delete[] temp;  
	}


	shapes[nShape] = a;
	++nShape;

	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape << '\n';
	cout << "Gened Shape: " << a->shapeType << '\n';

	printStatus(a->shapeType + " 도형을 만드는데 성공하였습니다"s);
}
void ShapeManager::draw() const
{
	printStatus("모든 도형을 그립니다");

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}

	printStatus("그리기를 마칩니다");
}
void ShapeManager::deleteSpecificShape() {
	printStatus("특정 도형을 모두 지웁니다");

	printStatus("특정 도형을 모두 지웠습니다");
}
void ShapeManager::deleteNthShape(int n) {
	printStatus("n번째 도형을 지웁니다");
	if (0 < nShape or nShape - 1 < n) {
		printStatus("잘 못된 숫자를 입력하였습니다", capacity, nShape);
		return;
	}
	
	

	printStatus("n번째 도형을 지웠습니다");
}



