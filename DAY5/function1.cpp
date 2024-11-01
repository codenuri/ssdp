// function1.cpp
#include <iostream>
#include <functional>

// 4항함수 : 인자가 4개인 함수
void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}
using namespace std::placeholders; // _1, _2, _3 ...

int main()
{
	foo(1, 2, 3, 4);
	// std::bind() 사용법 : std::bind(M항함수주소, M개인자)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // foo의 인자4개를
						// 1, 2, 3, 4 로 고정한 새로운 함수 f1
						// 4항 => 0항 함수로 변경
	f1();

	auto f2 = std::bind(&foo, 3, 8, _1, _2); // 4항 => 2항
	f2(4, 7); // foo(3, 8, 4, 7)


	auto f3 = std::bind(&foo, _2, 3, _3 , _1 );

	f3(8, 2, 6); // foo(2, 3, 6, 8) 되도록 ? 채우세요
}

// 파이썬 : functools.partial(함수, 인자...) 