// --------------------------
// ShapeManager.h		여러 개의 도형을 관리하는 클래스
// 
// --------------------------
// Shape* (부모 클래스의 *)로 전체 도형을 관리하는 것이 핵심
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

	// 도형을 생성할 때 쓰는 함수
	Triangle* newTriangle(int);
	Circle* newCircle(int);
	Rectangle* newRectangle(int);
	Line* newLine(int);
	Shape* selShape(int, int);
	void insert(Shape*);
	//
	void draw() const;
	void deleteSpecificShape();
	void deleteNthShape(int);
	void increaseCapacity(Shape**);

public:
	explicit ShapeManager(int);		

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action(int);
};