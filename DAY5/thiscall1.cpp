#include <iostream>
// 핵심 1. 멤버 함수는 컴파일 하면 "객체주소(this)" 가 추가됩니다.
// 핵심 2. static 멤버 함수는 컴파일 하면 "객체주소(this)" 가 추가안됩니다.

class Point
{
	int x, y;
public:
	void set(int a, int b)	// void set( Point* this, int a, int b)
	{						// { 	
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}		

	static void foo(int n)
	{
		x = n;		// this->x = n 이 되어야 하는데
					// static 멤버 함수 안에서는 "this" 가 없다.
					// 그래서, error!
	}

};
int main()
{
	// static 멤버 함수는 객체 없이 호출 가능
	Point::foo(10); // 컴파일 되어도 "call Point::foo(10)"

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) 을 변경됩니다.
}



