#include <iostream>

int main()
{
	char sa1[] = "ABCD";
	char sa2[] = "ABCD";

	const char* sp1 = "DEFG";
	const char* sp2 = "DEFG";

	// �Ʒ� ��������� ������. ���� �ּ� ? �ٸ� �ּ� ?
	printf("%p, %p\n", sa1, sa2);
	printf("%p, %p\n", sp1, sp2);
}