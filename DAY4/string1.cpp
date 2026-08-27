// string1.cpp
#include <iostream>

// 문자열 이야기
// => C/C++/C#/Java/Rust 등을 이해 하려면 반드시 알아야 합니다

int main()
{

	// 아래 코드에서 "hello" 문자열은 어느 메모리에 있을까요 ?
	char sa[] = "hello";
//	char* sp = "hello";  // C 언어 ok, C++ 언어 error
	const char* sp = "hello"; // C++ ok

	*sa = 'A';  // ok
	*sp = 'A';  // char* 인경우 C 언어 "runtime error" 
				// const char* 인 경우 compile error


}