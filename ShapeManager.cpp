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

bool ShapeManager::action(int option) {
	string shape, way{};
	switch (option) {
	case 1:	
		cout << "(����) (���� ���): ";
		cin >> shape >> way;
		insert(selShape(shape[0] - '0', way[0] - '0'));
		return true;
	case 2: draw();
		return true;
	case 3: deleteSpecificShape();
		return true;
	case 4: deleteNthShape();
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
			//�� 3�� ���
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

	printStatus("������ ����ϴ�");

	if (nullptr == a) {
		cout << "1 (����) (���� ���)\n";
		cout << "����		: 1 - ��, 2 - ���簢��, 3 - �ﰢ��, 4 - ��\n";
		cout << "���� ���	: default - �⺻ ����, 2 - ���� �Է��ؼ� ����\n";
		printStatus("������ ����µ� �����Ͽ����ϴ�");
		return;
	}

	if (nShape == capacity) {
		capacity = capacity + 1;
		shapes = new Shape * [capacity];
	}

	shapes[nShape++] = a;
	
	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape << '\n';
		
	printStatus("������ ����µ� �����Ͽ����ϴ�");
}

void ShapeManager::draw() const
{
	printStatus("��� ������ �׸��ϴ�");

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}

	printStatus("�׸��⸦ ��Ĩ�ϴ�");
}

void ShapeManager::deleteSpecificShape() {
	printStatus("Ư�� ������ ��� ����ϴ�");

	printStatus("Ư�� ������ ��� �������ϴ�");
}

void ShapeManager::deleteNthShape() {
	printStatus("n��° ������ ����ϴ�");

	printStatus("n��° ������ �������ϴ�");
}
