// git 에서 4_메뉴이벤트2.cpp 복사하세요
#include <iostream>
#include <functional> // 이헤더에 std::bind() 있습니다.
using namespace std::placeholders; // _1, _2, _3 ....

void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4);	// foo 는 4항 함수

	// std::bind : M 항 함수의 특정 인자로 고정한 N 항 함수 만드는 도구
	//			   단, M >= N

	// 사용법 : std::bind( M항 함수주소, M개 인자 )

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4항함수 => 0항 함수로 변경

	f1();	// foo(1,2,3,4)


	auto f2 = std::bind(&foo, 3, _1, 7, _2); // 4항수 => 2항함수로

	f2(6, 9); // foo(3, 6, 7, 9);



	auto f3 = std::bind(&foo, _3, 2, _1, _2 );  // ? 채우세요


	f3(9, 3, 1);  // foo(1, 2, 9, 3) 되도록 위 ? 채우세요

	// std::bind 의 반환 타입은
	// => std::bind() 의 인자에 따라 다른 타입으로 반환 됩니다.
	// => 그래서 auto 에 담아서 사용했습니다.
	// => 다른 방법은 "다음예제" 에서.. 


	// 파이썬 : functools.partial() 이 std::bind 역활


}
