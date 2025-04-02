#include <iostream>
#include <string> // 문자열 소유
#include <string_view> //const char* 의 의미

int main()
{
	char sa1[] = "ABCD";
	char sa2[] = "ABCD";

	const char* sp1 = "DEFG";
	const char* sp2 = "DEFG";

	// 아래 결과예측해 보세요. 같은 주소 ? 다른 주소 ?
	printf("%p, %p\n", sa1, sa2); // 다른 주소
	printf("%p, %p\n", sp1, sp2); // 같은 주소
	std::string s1 = "ABCD";
	std::string s2 = "ABCD";

	std::string_view sv1 = "DEFG";
	std::string_view sv2 = "DEFG";

	printf("%p, %p\n", s1.data(), s2.data());
	printf("%p, %p\n", sv1.data(), sv2.data());

	// C#
//	string s1 = "ABCD";
//	string s2 = "ABCD"; // s1, s2 는 같은 메모리!!(intern pool)

//	string s3 = new string("ABCD");
						// ABCD를 다른 메모리에 할당해 달라.
						// s1, s2 와는 다른 메모리
						// 단, immutable 하므로 변경은 안됨
}