#include <iostream>

// 멤버 함수의 호출원리
// 1. 멤버 함수는 인자로 "this" 가 추가됩니다. - "this call" 이라고 합니다.
// 2. static 멤버 함수는 this 가 추가되지 않는다.
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{					   // {	
		x = a;			   //		this->x = a;
		y = b;			   //		this->y = b;	
	}		

	static void foo(int a) // void foo(int a)
	{
		x = a;				// this->x = a; 로 변경해야 하는데..
	}						// 이 함수 안에는 this 가 없다.
							// 인자로 추가 안됨.
							// 그래서, static 멤버 함수안에서는
							// 멤버 데이타 접근 안됨. 
};
int main()
{
	Point::foo(10); // call Point::foo(10)

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20)
	p1.set(10, 20); // set(&p2, 10, 20)
}



