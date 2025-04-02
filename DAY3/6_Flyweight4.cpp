#include <iostream>
// C 언어는 아래 코드 컴파일 에러 아닙니다.
int main()
{
	// 아래 2줄의 차이점을 정확히 생각해 보세요
	char sa[] = "ABCD";	// 문자열 배열 ( NULL 문자 포함해서 5개크기)

	char* sp  = "DEFG";	// 문자열 포인터		
						// 상수메모리에 문자열이 있고
						// 스택에 있는 포인터가 sp 를 가리키게 됩니다.
						// C 언어 ok. C++ error

//	const char* sp = "DEFG"; //C++ ok. 이 경우 아래 *sp = 'x' 는	
							 // 컴파일 에러

	*sa = 'X'; // ok
	*sp = 'X'; // runtime error. 상수메모리는 변경 안됨.
}