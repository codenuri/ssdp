// function1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...


void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

void foo1(int a) {}
void foo2(int a, int b) {}

int main()
{
	// C언어의 함수 포인터는 유연성이 부족합니다.
	void (*f1)(int) = &foo1; // ok
	f1 = &foo2; // ??

}

