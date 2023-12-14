// --------------------------
// ShapeManager.h		여러 개의 도형을 관리하는 클래스
// 
// --------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심
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