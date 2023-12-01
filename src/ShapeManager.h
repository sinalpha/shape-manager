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


	Triangle* newTriangle(int);
	Circle* newCircle(int);
	Rectangle* newRectangle(int);
	Line* newLine(int);
	Shape* selShape(int, int);
	void insert(Shape*);
	void draw() const;
	void deleteSpecificShape();
	void deleteNthShape();

public:
	explicit ShapeManager(int);		// 담을 수 있는 도형의 갯수를 생섲자에 전달
										// explicit 사용법을 알아보자
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action(int);
};