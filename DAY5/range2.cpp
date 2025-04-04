// range1
#include <iostream>
#include <vector>
#include <ranges>  // �� �ȿ� take_view ���� �ֽ��ϴ�
					// ��, C++20 ���� �̹Ƿ� ���� ���߼���

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	// #1. ��ø ���
	std::ranges::take_view tv(v, 5);
	std::ranges::reverse_view rv(tv);
	std::ranges::filter_view  fv(rv, [](int n) { return n % 2 == 0; });


	for (auto e : fv) // 4, 2
	{
		std::cout << e << ", ";
	}

	std::cout << std::endl;
}