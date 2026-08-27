// string1.cpp
#include <iostream>

int main()
{
	// 문자열 배열 : 문자열 소유
	char sa1[] = "hello";
	char sa2[] = "hello";

	// 문자열 포인터 : 같은 문자열을 공유하게 됩니다.
	const char* sp1 = "hello"; 
	const char* sp2 = "hello"; 

	// 아래 결과를 예측해 보세요. 같은 주소 vs 다른 주소
	printf("%p, %p\n", sa1, sa2);	// 다른 주소
	printf("%p, %p\n", sp1, sp2);	// 같은 주소

}