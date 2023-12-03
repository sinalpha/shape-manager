// --------------------------
// ShapeManager.h		���� ���� ������ �����ϴ� Ŭ����
// 
// --------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
// --------------------------
// 2023. 11. 19		by Wulong
// --------------------------
#pragma once
#include "shape.h"
#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"

enum SHAPE_TYPE {
	NONE = 0,
	CIRCLE,
	RECTANGLE,
	TRIANGLE,
	LINE
};

enum ACTION_TYPE {
	CREATE_SHAPE = 1,
	DRAW_SHAPE,
	DELETE_SPEC_SHPAE,
	DELETE_NTH_SHAPE,
	SAVE_SHAPE,
	LOAD_SHAPE,
};


class ShapeManager {
	int nShape;
	int capacity;
	Shape** shapes;

	std::string getShapeType(Shape*) const;
	void printStatus(const std::string& status) const;
	void printStatus(const std::string& status, int capacity, int nShape) const;

public:
	explicit ShapeManager(int);		

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	void insert(Shape*);
	void draw() const;
	void save(const std::string&) const;
	void load(const std::string&);
	void deleteSpecificShape(const std::string&);
	void deleteNthShape(int);
	void increaseCapacity();
	bool action(int, const std::string&, Shape*);

};