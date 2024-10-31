#include <vector>
#include <iostream>
#include <ranges> // C++20 부터. 30여개의 view 가 제공됩니다.
				  // C++언어 설정을 C++20 으로 - 프로젝트메뉴, 속성메뉴

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	/*
	std::ranges::take_view    tv(v, 5);
	std::ranges::filter_view  fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);
	*/

	auto rv = v | std::views::take(5)
				| std::views::filter( [](int n) { return n % 2 == 0; } )
				| std::views::reverse;

	for (auto e : rv) // 생각해보세요
	{
		std::cout << e << ", ";
	}
	std::cout << "\n";
}