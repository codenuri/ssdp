// 구현을 담을 클래스
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug; // 코드가 수정되었다
public:
	void print();
};


// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 

//-----------------------------------------
// 사용자가 사용하는 클래스
// Point.h

// 핵심 : 전방선언만 있으면 
//       포인터변수는 선언가능
class PointImpl;

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h" // 여기서는 헤더 필요

Point::Point() { impl = new PointImpl(); }
void Point::print() { impl->print(); }







// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// PIMPL 이라는 C++ Idioms
// => Bridge 패턴을 컴파일시간 활용

// 장점 1. 컴파일 시간이 빨라진다.
//        => 컴파일러 방화벽!!

// 장점 2. 완벽한 정보 은닉
//		=> 최종 사용자가 받는 헤더에는
//		   멤버 데이타 노출 안됨