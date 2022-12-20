// bind1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // f4는 4항 함수 입니다.

	// std::bind() : M항함수를 N 항 함수로 변경하는 도구(단, M > N)
	// 사용법       : std::bind(M항함수주소, M개 인자)

	std::bind(&f4, 1, 2, 3, 4) ( ); // 결국 f4(1,2,3,4)
	//<--결과가 다시 함수----->|		// "4항함수" => "0항함수" 로변경

	std::bind(&f4, 5, _1, 9, _2) (6, 3);// f4(5, 6, 9, 3) 의 결과
										// "4항함수" => "2항함수"

	std::bind(&f4, 4개적으세요)(7, 9, 3); // f4(3, 2, 7, 9) 의 결과
}



