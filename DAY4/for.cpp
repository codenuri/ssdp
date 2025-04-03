//for.cpp
#include <iostream>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;
};

int main()
{
	Point3D p;

	for (auto e : p)
	{
		std::cout << e << std::endl;
	}
}
// 컴파일 해보세요. 에러 메세지 확인하세요

