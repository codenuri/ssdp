//for.cpp
#include <iostream>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	// �����ʹ� �ᱹ, ++, *, !=, == ���� ��� �����մϴ�.��, �ݺ��� �Դϴ�.
	int* begin() { return &x; }
	int* end()  { return &z + 1; }
};
int main()
{
	Point3D p;

	for (auto e : p)
	{
		std::cout << e << std::endl;
	}
}
// ������ �غ�����. ���� �޼��� Ȯ���ϼ���

