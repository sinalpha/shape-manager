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

	nShape = 0;			
	capacity = n;
	shapes = new Shape*[capacity];

}

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	delete[] shapes;

}

bool ShapeManager::insert(Shape* a)
{
	
	if (nullptr == a)
		return false;
	
	if (nShape == capacity)
		increaseCapacity();
	
	shapes[nShape] = a;
	++nShape;

	return true;

}

void ShapeManager::deleteAllShape() {
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];

	nShape = 0;
}

void ShapeManager::draw() const
{

	if (nShape <= 0)
		return;

	std::cout << "---------------------------------------" << '\n';
	std::cout << "��� ������ �׸��ϴ�" << '\n';
	std::cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << '\n';
	std::cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << '\n';
	std::cout << "---------------------------------------" << '\n';

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "]  ";
		shapes[i]->draw();
	}

	std::cout << "---------------------------------------" << '\n';
	std::cout << "�׸��⸦ ��Ĩ�ϴ�" << '\n';
	std::cout << "---------------------------------------" << '\n';

}

Shape* ShapeManager::returnNthShape(int i) const {

	if (0 >= i or i > nShape)
		return nullptr;

	return shapes[i - 1];

}

void ShapeManager::deleteNthShape(int n) {

	if (0 >= n or nShape < n) 
		return;

	int idx = n - 1;
	delete shapes[idx];
	// To Do memcpy�� ��������
	for (int i = idx; i < nShape - 1; ++i)
		shapes[i] = shapes[i + 1];
	--nShape;

}

void ShapeManager::increaseCapacity() {

	Shape** temp = shapes;
	capacity = capacity * 2;
	shapes = new Shape * [capacity];
	memcpy(shapes, temp, sizeof(Shape*) * nShape);
	delete[] temp;

}

void ShapeManager::save(const string& fileName) const {

	ofstream out{ fileName };
	for (int i = 0; i < nShape; ++i)
		out << shapes[i]->save() + " ";

}

void ShapeManager::load(ifstream& in, Shape* loadedShape) {




	in >> *loadedShape;
	insert(loadedShape);

}
