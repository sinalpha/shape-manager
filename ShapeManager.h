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


	Triangle* newTriangle();
	Circle* newCircle();
	Rectangle* newRectangle();
	Line* newLine();
	Shape* selShape();
	void insert(Shape*);
	void draw() const;
	void deleteSpecificShape();
	void deleteNthShape();
	

public:
	explicit ShapeManager(int n);		// ���� �� �ִ� ������ ������ ���A�ڿ� ����
										// explicit ������ �˾ƺ���
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	bool action();
};