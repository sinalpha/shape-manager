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
		cout << "�������� �Է����� ������ �Ѥ�;(�ʼ� ��ɸ� ������)\n";

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
	case CREATE_SHAPE:
		cout << "(����) (���� ���): ";
		cin >> input1 >> input2;
		insert(selShape(input1[0] - '0', input2[0] - '0'));
		return true;
	case DRAW_SHAPE:
		draw();
		return true;
	case DELETE_SPEC_SHPAE:
		cout << "� ������ ����ڽ��ϱ�?: ";
		cin >> input1;
		deleteSpecificShape(input1);
		return true;
	case DELETE_NTH_SHAPE:
		cout << "���� �����ϰ� �ִ� ���� - " << nShape << " ���� ������ ��ġ: ";
		cin >> input1;
		deleteNthShape(stoi(input1));
		return true;
	case SAVE_SHAPE:
		cout << "������ ������ ��ġ�� �Է��Ͻÿ�: ";
		cin >> input1;
		save(input1);
		return true;
	case LOAD_SHAPE:
		cout << "�ε��� ������ �Է��Ͻÿ�: ";
		cin >> input1;
		load(input1);
		return true;
	default:
		return false;
	}

}


void ShapeManager::insert(Shape* a)
{

	printStatus(a->shapeType + " ������ ����ϴ�");


	if (nullptr == a) {
		printStatus(insertHelp);
		return;
	}

	if (nShape == capacity)
		increaseCapacity();
	shapes[nShape] = a;
	++nShape;
	printStatus("���� �� ���", capacity, nShape);

	printStatus(a->shapeType + " ������ ����µ� �����Ͽ����ϴ�"s);

}
void ShapeManager::draw() const
{

	printStatus("�����ϴ� ��� ������ �׸��ϴ�", capacity, nShape);

	if (nShape <= 0)
		printStatus("�׸� ������ �����ϴ�");

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();
	}

	printStatus("�׸��⸦ ��Ĩ�ϴ�");

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
			printStatus("�б⸦ �����Ͽ����ϴ�");
			return;
		}
	}

	printStatus("�б⸦ ���������� ���ƽ��ϴ�");

}



