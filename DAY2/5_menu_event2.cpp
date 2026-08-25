#include <iostream>
#include <functional> 
using namespace std::placeholders; 

void foo()
{
	std::cout << "foo\n";
}

int main()
{
	// C 언어 함수 포인터 : "함수의 주소" 를 보관하는 타입
	void(*f)() = &foo;
}
