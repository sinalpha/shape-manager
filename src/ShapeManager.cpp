// --------------------------
// ShapeManger.cpp	������ �����ϴ� Ŭ����
// 
// 2023. 11. 19		by Wulong
// --------------------------
#include <iostream>
#include "shapeManager.h"
#include "utility.h"

using namespace std;

ShapeManager::ShapeManager(int n)
{
	printStatus("������ �����մϴ�");

	nShape = 0;			
	capacity = n;
	shapes = new Shape*[capacity];
}
ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;

	printStatus("������ �����մϴ�");
}
bool ShapeManager::action(int option) {
	string input1, input2{};
	switch (option) {
	case 1://���� ����
		cout << "(����) (���� ���): ";
		cin >> input1 >> input2;
		insert(selShape(input1[0] - '0', input2[0] - '0'));
		return true;
	case 2://���� �׸���
		draw();
		return true;
	case 3://Ư�� ���� �����
		cout << "� ������ ����ڽ��ϱ�?: ";
		cin >> input1;
		deleteSpecificShape(stringToInt(input1));
		return true;
	case 4://n��° ���� �����
		cout << "���� NUM - " << nShape << " ���� ������ ��ġ: ";
		cin >> input1;
		deleteNthShape(input1[0] - '0');
		return true;
	default:
		return false;
	}
}

Shape* ShapeManager::selShape(int shape,int way) {
	switch (shape) {
	case CIRCLE:
		return newCircle(way);
	case RECTANGLE:
		return newRectangle(way);
	case TRIANGLE:
		return newTriangle(way);
	case LINE:	
		return newLine(way);
	default: 
		return nullptr;
	}
	
} 
Triangle* ShapeManager::newTriangle(int way) const{
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
Circle* ShapeManager::newCircle(int way) const{
	
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
Rectangle* ShapeManager::newRectangle(int way) const{
	
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
Line* ShapeManager::newLine(int way) const {
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

	if (nShape == capacity)
		increaseCapacity();
	shapes[nShape] = a;
	++nShape;

	cout << "Capacitiy: " << capacity << '\n';
	cout << "NUM: " << nShape << '\n';
	cout << "Gened Shape: " << a->shapeType << '\n';

	printStatus(a->shapeType + " ������ ����µ� �����Ͽ����ϴ�"s);
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
void ShapeManager::deleteNthShape(int n) {
	printStatus(char(n + '0') + "��° ������ ����ϴ�"s);
	
	if (0 >= nShape or nShape < n) {
		printStatus("�߸��� ���ڸ� �Է��Ͽ����ϴ�", capacity, nShape);
		return;
	}
	
	delete shapes[n - 1];
	//memcpy�� ��������
	for (int i = n - 1; i < nShape - 1; ++i)
		shapes[i] = shapes[i + 1];
	--nShape;

	printStatus(char(n + '0') + "��° ������ �������ϴ�"s);
}

void ShapeManager::increaseCapacity() {
	printStatus("���� �뷮�� �ø��ϴ�.");
	Shape** temp = shapes;
	capacity = capacity * 2;
	shapes = new Shape * [capacity];
	memcpy(shapes, temp, sizeof(Shape*) * nShape);
	delete[] temp;
}



