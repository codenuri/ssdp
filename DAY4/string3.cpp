#include <iostream>
#include <string>
#include <string_view>

int main()
{
	// std::string      : 문자열을 소유
	// std::string_view : 기존 문자열에 대한 view

	std::string s1 = "hello";

	// 아래 2줄의 메모리 그림이 중요합니다.
	std::string s2      = s1;	// s2 가 s1의 문자열의 
								// 복사본을 생성해서 소유
	std::string_view sv1 = s1;	// sv 가 "s1.버퍼주소" 를 가리키는것
								// 즉, const char*


	// 아래 2줄의 메모리 그림도 알아야 합니다.
	// 핵심 : string_view 가 직접 literal 로 초기화 될때

	std::string s3       = "hello";
	std::string_view sv2 = "hello";

	// 참고 : std::string_view 는 읽기만 가능
}