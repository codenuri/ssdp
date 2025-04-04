// range1
#include <iostream>
#include <vector>
#include <ranges>  // 이 안에 take_view 등이 있습니다
					// 단, C++20 부터 이므로 버전 맞추세요

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	// #1. 중첩 허용
//	std::ranges::take_view tv(v, 5);
//	std::ranges::reverse_view rv(tv);
//	std::ranges::filter_view  fv(rv, [](int n) { return n % 2 == 0; });


	// #2. syntax sugar 
	// => 위 코드와 완전히 동일한 코드인데, 사용하기 쉽게 만들어 놓은것
	auto fv = v | std::views::take(5)
				| std::views::reverse
				| std::views::filter([](int n) { return n % 2 == 0; });

	// C#
//	var c = arr.Where(람다조건식).OrderBy(..).Reverse();


	for (auto e : fv) // 4, 2
	{
		std::cout << e << ", ";
	}

	std::cout << std::endl;
}