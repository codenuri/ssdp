﻿// C++진영에서의 Bridge 의 응용

// Point.h
class Point
{
	int x, y;
public:
	void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // 구현 생략



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


