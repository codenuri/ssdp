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
	f();	// ok. foo()

	// 람다표현식도 저장 가능
	// => 정확히는 "캡쳐하지 않은 람다 표현식은 함수 포인터로 변환 가능" 한것
	f = []() { std::cout << "lambda expression\n"; };
	f();

	// 단, 캡쳐한 람다 표현식은 함수 포인터에 저장 못함
	// => 캡쳐한 람다 표현식은 함수 포인터로 변환 안됨
	int n = 0;

	f = [n]() { std::cout << n << '\n'; }; // error
}







