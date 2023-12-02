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
#include "utility.h"

class ShapeManager {
	int nShape;
	int capacity;
	Shape** shapes;

	// 도형을 생성할 때 쓰는 함수
	Triangle* newTriangle(int) const;
	Circle* newCircle(int) const;
	Rectangle* newRectangle(int) const;
	Line* newLine(int) const;
	Shape* selShape(int, int);
	
	//
	void deleteSpecificShape(const std::string&);
	void deleteNthShape(int);
	void increaseCapacity();
	void save(const std::string&) const;
	void load(const std::string&);

public:
	explicit ShapeManager(int);		

	void insert(Shape*);
	void draw() const;

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action(int);
};