// 실제 구현 계층
// Point 의 모든 구현은 이 클래스에 구현합니다.

// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void print();
};


// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { }
//------------------------------

// 추상층(bridge)
// => 사용자가 실제 사용하는 클래스
// => 구현은 "PointImpl"에 의존

// Point.h

class PointImpl; // 클래스 전방선언
				 // 헤더 파일이 없어도
				 // 포인터 변수는 선언 가능
class Point
{
	PointImpl* impl; // 구현을 가리키는 포인터
public:
	Point();
	void print();
};


// Point.cpp
#include "PointImpl.h" // 여기서는 헤더 필요
#include "Point.h"
Point::Point()      { impl = new PointImpl; }
void Point::print() { impl->print(); }


// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


