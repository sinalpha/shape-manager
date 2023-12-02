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
	bool action(int);

};