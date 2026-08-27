#include <iostream>
#include <string>
#include <string_view>

// 인자로 받는 문자열을 읽기만 하려고 합니다
// 다음중 가장 좋은 코드는 ?

void f1(std::string s)        {}	// bad. 복사본 생성

void f2(const std::string& s) {}	// 나쁘지는 않지만 최선은 아니다



void f3(std::string_view s)   {}	// best


int main()
{
	std::string s = "hello";
	f1(s);

	// 아래 경우는 f2, f3 의 성능이 유사하다고 볼수 있습니다.
	f2(s);
	f3(s);

	// 문제는 아래 코드
	f2("hello");	// 이 순간 std::string temporary("hello") 의미의 객체 생성후
					//	f2(temporary)
	f3("hello");	// 이 순간 temporary 생성 안됩니다.
					// 따라서 이코드가 훨씬 좋은 코드
}

//				문자열을 소유하는 타입			문자열에 대한 view
// C++			std::string						std::string_view
// Rust			String							str
// C#			StringBuilder					string

// C++20 부터 std::string_view 의 일반화 버전이 도입되었습니다.
// std::span  : "문자열에 대한 뷰" 가 아닌 "임의 타입 T 의 뷰"
//				std::vector 나 array 를 받을때 사용


