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

	switch (getOption("�� �ൿ�� �����Ͻÿ� Help:0: ")){
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
		cout << "1: ���ϴ� ���� �߰�\n";
		cout << "2: ��ü ������ �׸���\n";
		cout << "3: n��° ������ ����\n";
		cout << "4: ���ϴ� ������ ��� ����\n";
		cout << "5: ���α׷� �����ϱ�\n";
	}

	return true;
}

Shape* ShapeManager::selShape() {

	switch (getOption("�߰��� ������ �����Ͻÿ�: ")) {
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
		switch (getOption("������ ����� �����Ͻÿ�: ")) {
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
			cout << "1 - ����Ʈ ����\n";
			cout << "2 - ������ ����\n";
		}
	}
}

Circle* ShapeManager::newCircle() {
	
	while (true) {
		Point point;
		double r;
		switch (getOption("������ ����� �����Ͻÿ�: ")) {
		case 1:
			return new Circle;
		case 2:
			cout << "input x, y, r" <<  '\n';
			cin >> point.x >> point.y >> r;
			return new Circle(point, r);
		default:
			cout << "1 - ����Ʈ ����\n";
			cout << "2 - ������ ����\n";
		}
	}
}

Rectangle* ShapeManager::newRectangle() {
	
	while (true) {
		Point points[2];
		switch (getOption("������ ����� �����Ͻÿ�: ")) {
		case 1:
			return new Rectangle;
		case 2:
			for (int i = 0; i < 2; ++i) {
				cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				cin >> points[i].x >> points[i].y;
			}
			return new Rectangle(points[0], points[1]);
		default:
			cout << "1 - ����Ʈ ����\n";
			cout << "2 - ������ ����\n";
		}
	}
}

Line* ShapeManager::newLine() {
	while (true) {
		Point points[2];
		switch (getOption("������ ����� �����Ͻÿ�: ")) {
		case 1:
			return new Line;
		case 2:
			for (int i = 0; i < 2; ++i) {
				std::cout << "input x" << i + 1 << ", y" << i + 1 << '\n';
				std::cin >> points[i].x >> points[i].y;
			}
			return new Line(points[0], points[1]);
		default:
			std::cout << "1 - ����Ʈ ����\n";
			std::cout << "2 - ������ ����\n";
		}
	}
}

void ShapeManager::insert(Shape* a)
{

	cout << "-----------------------" << '\n';
	cout << "������ ����ϴ�." << '\n';
	cout << "-----------------------" << "\n\n";
	if (a == nullptr) {
		cout << "----------------------" << '\n';
		cout << "������ ����µ� �����Ͽ����ϴ�.\n";
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
	cout << "������ ����µ� �����Ͽ����ϴ�.\n";
	cout << "----------------------" << "\n\n";
}

void ShapeManager::draw() const
{
	cout << "-----------------------" << '\n';
	cout << "��� ������ �׸��ϴ�." << '\n';
	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape <<  '\n';
	cout << "-----------------------" << "\n\n";

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}
	cout << '\n';

	cout << "----------------------" << '\n';
	cout << "�׸��⸦ ��Ĩ�ϴ�." << '\n';
	cout << "----------------------" << "\n\n";
}

void ShapeManager::deleteSpecificShape() {
	cout << "���� �� ��\n";
}

void ShapeManager::deleteNthShape() {
	cout << "���� �� ��\n";
}