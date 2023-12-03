// --------------------------
// ShapeManger.cpp	������ �����ϴ� Ŭ����
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
	printStatus("������ �����մϴ�"s);

	nShape = 0;			
	capacity = n;
	shapes = new Shape*[capacity];
}
ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;

	printStatus("������ �����մϴ�"s);
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

	printStatus("������ ����ϴ�");

	if (nullptr == a) {
		printStatus("������ ����µ� �����Ͽ����ϴ�");
		return;
	}

	if (nShape == capacity)
		increaseCapacity();
	
	shapes[nShape] = a;
	++nShape;
	printStatus("���� �� ���", capacity, nShape);

	printStatus("������ ����µ� �����Ͽ����ϴ�"s);

}
void ShapeManager::draw() const
{

	printStatus("�����ϴ� ��� ������ �׸��ϴ�"s, capacity, nShape);

	if (nShape <= 0)
		printStatus("�׸� ������ �����ϴ�"s);

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();
	}

	printStatus("�׸��⸦ ��Ĩ�ϴ�"s);

}
void ShapeManager::deleteSpecificShape(const string& type) {

	printStatus(type + "�� ��� ����ϴ�");

	// To Do O(n)���� �����
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
	// To Do memcpy�� ��������
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

	printStatus("��� ������ "s + fileName + "�� �����մϴ�"s);

	ofstream out{ fileName };
	for (int i = 0; i < nShape; ++i)
		out << to_string(ConvertShapeTypeToInt(getShapeType(shapes[i]))) + " " + shapes[i]->save() + " ";

	printStatus("��� ������ "s + fileName + "�� ������ �Ͽ����ϴ�"s);

}
void ShapeManager::load(const string& fileName) {

	printStatus(fileName + "���� �б⸦ �����մϴ�"s);

	ifstream in{ fileName };
	if (not in) {
		printStatus(fileName + "�� �������� �ʽ��ϴ�"s);
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
			printStatus("�б⸦ �����Ͽ����ϴ�");
			return;
		}
	}

	printStatus("�б⸦ ���������� ���ƽ��ϴ�");

}



string ShapeManager::getShapeType(Shape* shape) const {
	if (dynamic_cast<Line*>(shape))
		return "��";

	if (dynamic_cast<Circle*>(shape))
		return "��";

	if (dynamic_cast<Rectangle*>(shape))
		return "�簢��";

	if (dynamic_cast<Triangle*>(shape))
		return "�ﰢ��";

	return "None";
}

int ShapeManager::ConvertShapeTypeToInt(const string& str) const {
	if ("�ﰢ��" == str)
		return TRIANGLE;
	if ("�簢��" == str)
		return RECTANGLE;
	if ("��" == str)
		return CIRCLE;
	if ("��" == str)
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
	std::cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << '\n';
	std::cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << '\n';
	std::cout << "---------------------------------------" << '\n';
}
