#include <iostream>

// 핵심 
// 1. 멤버 함수는 인자로 "this" 가 추가됩니다. - this call 이라고 합니다
// 2. static 멤버 함수는 "this" 가 추가되지 않습니다.

class Point
{
	int x = 0;
	int y = 0;
public:
	void set(int a, int b)	// void set( Point* this, int a, int b)
	{						// {
		x = 0;				//		this->x = 0;
		y = 0;				//		this->y = 0; 으로 변경됩니다.
			
		std::cout << this << std::endl;
	}

	static void foo(int a)	// void foo(int a)
	{						// {
		x = a;				//		this->x = a; 되야 하는데, 
							//				this 가 없으므로 에러. 
	}
};
int main()
{
	Point::foo(10);	// call Point::foo(10)

	Point p1;
	Point p2;

	p1.set(10, 20); // call Point::set(&p1, 10, 20)
					// 처럼 변경됩니다.
}