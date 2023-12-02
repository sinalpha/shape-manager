// --------------------------
// ShapeManager.h		���� ���� ������ �����ϴ� Ŭ����
// 
// --------------------------
// Shape* (�θ� Ŭ������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
// --------------------------
// 2023. 11. 19		by Wulong
// --------------------------
#include "shape.h"
#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"

class ShapeManager {
	int nShape;
	int capacity;
	Shape** shapes;

	// ������ ������ �� ���� �Լ�
	Triangle* newTriangle(int) const;
	Circle* newCircle(int) const;
	Rectangle* newRectangle(int) const;
	Line* newLine(int) const;
	Shape* selShape(int, int);
	void insert(Shape*);
	//
	void draw() const;
	void deleteSpecificShape();
	void deleteNthShape(int);
	void increaseCapacity();

public:
	explicit ShapeManager(int);		

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action(int);
};