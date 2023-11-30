// --------------------------
// Point.h		class Shape - Virtual Base Class
//				�� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
// 
// 2023. 11. 19	by Wulong
// --------------------------
#pragma once

class Shape
{
public:
	Shape() { };
	virtual ~Shape() { };

	virtual void draw() const = 0;	// pure virtual function
};