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