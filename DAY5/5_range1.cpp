// 5_range1.cpp
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6 };

	for (auto e : v)
	{
		std::cout << e << std::endl;
	}

	// 위 for 문의 원리
	auto first = v.begin();
	auto last  = v.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//-----------------------------
		// 이 위치에 사용자 코드
	}
}