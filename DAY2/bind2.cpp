// bind1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

void f1(int a) {}
void f2(int a, int b) {}

int main()
{
	// 함수 포인터는 유연성이 부족합니다
//	void(*f)(int) = &f1; // ok
//	f(10);			     // f1(10)
//	f = &f2; // error. f2는 인자가 2개 입니다.

	// C++11 부터는 std::function<> 사용하세요
	std::function<void(int)> f;

	f = &f1;
	f(10);  // ok. f1(10)

	
	// 핵심 : function 은 std::bind()의 결과로 나오는 새로운 함수를 담을수
	// 있습니다.
	// f = &f2; // error

	f = std::bind(&f2, _1, 7);
	f(10); // f2(10, 7)


	f = std::bind(&f4, ? ? ? ? );
	f(6); // f4(7, 3, 6, 9) 나오게 해보세요


}





