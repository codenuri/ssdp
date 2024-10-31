// godbolt.org
#include <iostream>

int main()
{
	// #1.
//	printf("hello\n");	// 1. 상수메모리에 "hello" 문자열 만들고
						// 2. mov  edi, "상수메모리의 문자열주소"
						// 3. call printf


	// #2. 문자열 배열 vs 문자열 포인터
	char sa[] = "abcd";
//	char* sp  = "abcd"; // C ok. C++ error

	*sa = 'x'; // ok. stack 에 쓰기, R/W 가능
//	*sp = 'x'; // C 언어. runtime error
	
	const char* sp = "abcd"; // C++ ok
							// 즉, 반드시 const 필요


	// #3. flyweight
	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1 = "abcd";
	const char* sp2 = "abcd";

	printf("%p, %p\n", sa1, sa2); // 다른 주소
	printf("%p, %p\n", sp1, sp2); // 같은 주소(공유)
}



