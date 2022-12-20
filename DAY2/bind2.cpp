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

class Dialog
{
public:
	void close(int a, double d) { std::cout << "Dialog Close" << std::endl; }
};

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


	f = std::bind(&f4, 7, 3, _1, 9 );
	f(6); // f4(7, 3, 6, 9) 나오게 해보세요

	// 결국 "f" 에는 인자가 "int 한개" 이상인 모든 종류의 함수를 
	// 담을수 있습니다. std::bind() 덕분에.

	// 멤버 함수 주소를 담는 방법
	// => 멤버 함수를 호출하려면 객체가 필요 합니다.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1, 3.4);

	f(10); // dlg.close(10, 3.4) 의 의미!
}





