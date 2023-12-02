// --------------------------
// Point.h		class Shape - Virtual Base Class
//				�� Ŭ������ �߻� Ŭ����(abstract class)�̴�.
// 
// 2023. 11. 19	by Wulong
// --------------------------
#pragma once

#include <string>
#include <iostream>

class Shape
{
public:
	std::string shapeType{ "None" };
	
	Shape() { };
	Shape(std::string shapeType) : shapeType{ shapeType } { };
	virtual ~Shape() { };

	virtual std::string save() const = 0;
	virtual void draw() const = 0;	// pure virtual function

};