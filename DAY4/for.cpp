//for.cpp
#include <iostream>

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	// 포인터는 결국, ++, *, !=, == 연산 모두 가능합니다.즉, 반복자 입니다.
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
// 컴파일 해보세요. 에러 메세지 확인하세요

