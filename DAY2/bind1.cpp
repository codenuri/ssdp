// bind1.cpp
#include <iostream>
#include <functional>

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // f4는 4항 함수 입니다.

	// std::bind() : M항함수를 N 항 함수로 변경하는 도구(단, M > N)
	// 사용법       : std::bind(M항함수주소, M개 인자)

	std::bind(&f4, 1, 2, 3, 4)();
}