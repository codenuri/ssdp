#include <iostream>
#include <string>
#include <string_view>

int main()
{
	// std::string      : 문자열을 소유
	// std::string_view : 기존 문자열에 대한 view

	std::string s1 = "hello";

	// 아래 2줄의 메모리 그림이 중요합니다.
	std::string s2      = s1;
	std::string_view sv1 = s1;


	// 아래 2줄의 메모리 그림도 알아야 합니다.
	std::string s3       = "hello";
	std::string_view sv2 = "hello";
}