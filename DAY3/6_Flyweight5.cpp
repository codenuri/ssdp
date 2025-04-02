#include <iostream>
#include <string> // ���ڿ� ����
#include <string_view> //const char* �� �ǹ�

int main()
{
	char sa1[] = "ABCD";
	char sa2[] = "ABCD";

	const char* sp1 = "DEFG";
	const char* sp2 = "DEFG";

	// �Ʒ� ��������� ������. ���� �ּ� ? �ٸ� �ּ� ?
	printf("%p, %p\n", sa1, sa2); // �ٸ� �ּ�
	printf("%p, %p\n", sp1, sp2); // ���� �ּ�
	std::string s1 = "ABCD";
	std::string s2 = "ABCD";

	std::string_view sv1 = "DEFG";
	std::string_view sv2 = "DEFG";

	printf("%p, %p\n", s1.data(), s2.data());
	printf("%p, %p\n", sv1.data(), sv2.data());

	// C#
//	string s1 = "ABCD";
//	string s2 = "ABCD"; // s1, s2 �� ���� �޸�!!(intern pool)

//	string s3 = new string("ABCD");
						// ABCD�� �ٸ� �޸𸮿� �Ҵ��� �޶�.
						// s1, s2 �ʹ� �ٸ� �޸�
						// ��, immutable �ϹǷ� ������ �ȵ�
}