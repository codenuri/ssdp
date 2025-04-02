#include <iostream>

int main()
{
	char sa1[] = "ABCD";
	char sa2[] = "ABCD";

	const char* sp1 = "DEFG";
	const char* sp2 = "DEFG";

	// 아래 결과예측해 보세요. 같은 주소 ? 다른 주소 ?
	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}