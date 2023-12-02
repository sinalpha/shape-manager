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
#include "utility.h"

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
	void deleteSpecificShape(std::string);
	void deleteNthShape(int);
	void increaseCapacity();
	void save(std::string) const;
	void load(std::string);

public:
	explicit ShapeManager(int);		

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action(int);
};