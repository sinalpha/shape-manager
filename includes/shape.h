// --------------------------
// Point.h		class Shape - Virtual Base Class
//				이 클래스는 추상 클래스(abstract class)이다.
// 
// 2023. 11. 19	by Wulong
// --------------------------
#pragma once

#include <string>
#include <iostream>

class Shape
{
public:
	
	Shape() { };
	virtual ~Shape() { };

	virtual std::string save() const = 0;
	virtual void draw() const = 0;	
	virtual void load(std::ifstream&) = 0;

	friend Shape& operator>>(std::ifstream& in, Shape& shape) {
		
		shape.load(in);

		return shape;
	}

};