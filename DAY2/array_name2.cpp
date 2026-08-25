// array_name2.cpp
#include <iostream>

int main()
{
	int x[3] = { 1,2,3 };

	int(*p1)[3] = &x; // p1 은 "배열 x 의 주소"

	int* p2 = &x[0];  // p2 는 배열의 1번째 요소의 주소

	// p1, p2 가 같은 주소 지만, 타입이 다릅니다.
	// 포인터의 타입 : 다양한 연산자 사용시 어떻게 연산할지를 결정하는 것
	printf("%p, %p\n", p1, p1 + 1);
	printf("%p, %p\n", p2, p2 + 1);
}


