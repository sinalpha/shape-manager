// --------------------------
// ShapeManger.cpp	������ �����ϴ� Ŭ����
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
		cout << "�̻��� ���� �Է����� ������ �Ѥ�;(�ʼ� ��ɸ� ������)\n";

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
		if (nShape <= 0)
		{
			printStatus("�׸� ������ �����ϴ�");
			return true;
		}
		draw();
		return true;
	case 3://Ư�� ���� �����
		cout << "� ������ ����ڽ��ϱ�?: ";
		cin >> input1;
		deleteSpecificShape(input1);
		return true;
	case 4://n��° ���� �����
		cout << "���� NUM - " << nShape << " ���� ������ ��ġ: ";
		cin >> input1;
		deleteNthShape(stoi(input1));
		return true;
	case 5:
		cout << "������ ������ ��ġ�� �Է��Ͻÿ�: ";
		cin >> input1;
		save(input1);
		return true;
	case 6:
		cout << "�ε��� ������ �Է��Ͻÿ�: ";
		cin >> input1;
		load(input1);
		return true;
	default:
		return false;
	}
}

//private�Լ�
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
				cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
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
			cout << "�Է� x, y, r" <<  '\n';
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
				cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
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
				std::cout << "�Է� x" << i + 1 << ", y" << i + 1 << '\n';
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

	printStatus(a->shapeType + " ������ ����ϴ�");

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

	printStatus("���� �� ���", capacity, nShape);
	cout << "���� ����: " << a->shapeType << '\n';

	printStatus(a->shapeType + " ������ ����µ� �����Ͽ����ϴ�"s);
}
void ShapeManager::draw() const
{
	printStatus("�����ϴ� ��� ������ �׸��ϴ�", capacity, nShape);

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
	}

	printStatus("�׸��⸦ ��Ĩ�ϴ�");
}
void ShapeManager::deleteSpecificShape(const string& type) {
	printStatus(type + "�� ��� ����ϴ�");

	//��ȿ�������� ����� ������ ���߿� �����ؾ���

	for (int i = 0; i < nShape; ++i) {
		if (type == "�ﰢ��")
			if (dynamic_cast<Triangle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "��")
			if (dynamic_cast<Circle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "�簢��")
			if (dynamic_cast<Rectangle*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
		if (type == "��")
			if (dynamic_cast<Line*>(shapes[i])) {
				deleteNthShape(i + 1);
				i = -1;
			}
	}

	printStatus(type + "�� ��� �������ϴ�");
}
void ShapeManager::deleteNthShape(int n) {
	printStatus(to_string(n) + "��° ������ ����ϴ�"s);

	if (0 >= n or nShape < n) {
		printStatus("�߸��� ���ڸ� �Է��Ͽ����ϴ�", capacity, nShape);
		return;
	}

	int idx = n - 1;
	
	delete shapes[idx];
	//memcpy�� ��������
	for (int i = idx; i < nShape - 1; ++i)
		shapes[i] = shapes[i + 1];
	--nShape;

	printStatus(to_string(n) + "��° ������ �������ϴ�"s);
}
void ShapeManager::increaseCapacity() {
	printStatus("���� �뷮�� �ø��ϴ�.");
	Shape** temp = shapes;
	capacity = capacity * 2;
	shapes = new Shape * [capacity];
	memcpy(shapes, temp, sizeof(Shape*) * nShape);
	delete[] temp;
}
void ShapeManager::save(const string& fileName) const {

	printStatus("��� ������ " + fileName + "�� �����մϴ�");

	ofstream out{ fileName };


	for (int i = 0; i < nShape; ++i)
		out << shapes[i]->save() + " ";

	printStatus("��� ������ " + fileName + "�� ������ �Ͽ����ϴ�");

}
void ShapeManager::load(const string& fileName) {
	printStatus(fileName + "���� �б⸦ �����մϴ�");

	ifstream in{ fileName };
	if (not in) {
		printStatus(fileName + "�� �������� �ʽ��ϴ�");
		return;
	}

	int shape_type;
	Point p[3];
	double r;
	while (in >> shape_type) {
		switch (shape_type) {
		case TRIANGLE:
			for (int i = 0; i < 3; ++i)
				in >> p[i].x >> p[i].y;
			insert(new Triangle(p[0], p[1], p[2]));
			continue;
		case CIRCLE:
			in >> p[0].x >> p[0].y >> r;
			insert(new Circle(p[0], r));
			continue;
		case LINE:
			for (int i = 0; i < 2; ++i)
				in >> p[i].x >> p[i].y;
			insert(new Line(p[0], p[1]));
			continue;
		case RECTANGLE:
			for (int i = 0; i < 2; ++i)
				in >> p[i].x >> p[i].y;
			insert(new Rectangle(p[0], p[1]));
			continue;
		default:
			printStatus("�б⸦ �����Ͽ����ϴ�");
			return;
		}
	}

	printStatus("�б⸦ ���������� ���ƽ��ϴ�");
}



