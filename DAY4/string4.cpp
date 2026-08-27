#include <iostream>
#include <string>
#include <string_view>

// 인자로 받는 문자열을 읽기만 하려고 합니다
// 다음중 가장 좋은 코드는 ?

void f1(std::string s)        {}
void f2(const std::string& s) {}
void f3(std::string_view s)   {}

int main()
{
	std::string s = "hello";
	f1(s);
	f2(s);
	f3(s);

	f1("hello");
	f2("hello");
	f3("hello");
}