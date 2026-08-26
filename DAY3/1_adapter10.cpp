#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack> 
#include <queue>

// 요즘 대부분의 언어가(C++, C#, Java, Rust, Python 등)
// 라이브러리 설계할때 Adapter 패턴을 아주 많이 사용합니다

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	auto first = v.begin();
	auto last = v.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

