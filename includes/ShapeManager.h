// --------------------------
// ShapeManager.h		���� ���� ������ �����ϴ� Ŭ����
// 
// --------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
// --------------------------
// 2023. 11. 19		by Wulong
// --------------------------
#pragma once
#include <string.h>

#include "shape.h"

class ShapeManager {
	int nShape;
	int capacity;
	Shape** shapes;


public:
	explicit ShapeManager(int);		

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void deleteAllShape();
	bool insert(Shape*);
	void draw() const;
	void save(const std::string&) const;
	void load(std::ifstream&, Shape*);
	Shape* returnNthShape(int) const;
	void deleteNthShape(int);
	void increaseCapacity();



};