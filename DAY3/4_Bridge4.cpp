// 구현계층
// PointImpl.h
class PointImpl
{
	int degug; 
	int x, y;
public:
	void print();
};


// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() {}


// 아래 코드가 추상층(서비스)계층
// Point.h

class PointImpl; // 핵심
				// 전방선언만있으면
				// 포인터는 사용가능
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }
//--------------------------------------------



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}

// C++ IDIoms 중에서

// PIMPL 이라 불리는 기술

// Pointer to IMPLementation 의 약자

// 장점1. 컴파일 시간 빨라집니다
//     2. 완벽한 정보은닉..
//        최종사용자는 구현의 헤더 가 아닌 추상층의 헤더만 사용하게 됩니다.
//		  구현부를 완벽히 숨길수 있습니다.
