// git 에서 4_메뉴이벤트2.cpp 복사하세요
#include <iostream>
#include <functional>


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
}
