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
	// std::function<>   : 호출 가능한 "모든 것을" 보관하는 타입

	std::function<void()> f;

	f = &foo; // 함수포인터

	f = []() { std::cout << "lambda\n";  };

	// 캡쳐한 람다 표현식
	int n = 0;
	f = [n]() { std::cout << n + 1 << "\n"; };

	// 이 외에도, 멤버 함수, 함수객체 등 () 로 호출 가능한것은 모두 
	// 보관 가능


}







