//5_PIMPL.cpp


// 구현계층
// => 실제 Point 의 모든 기능은 여기에 구현
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug;
public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() {} 


// 추상층 
// => 사용자가 사용하는 클래스
// Point.h

class PointImpl; // 핵심
				 // 전방선언만 있으면 포인터 변수는 선언가능
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "Pointimpl.h"

Point::Point() { impl = new PointImpl; }

void Point::print() { impl->print(); }

// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// 장점
// #1. 구현의 헤더 변경시
// => 2개의 소스만 다시 빌드하면 된다

// #2. 완벽한 정보 은닉
// => 구현의 헤더를 외부에 노출할 필요 없다
// => 추상층의 헤더만 제공하면 된다
