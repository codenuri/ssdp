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

	// 정방향 반복자 : ++ 연산을 하면 --> 방향으로 이동
//	auto first = v.begin();
//	auto last = v.end();

	// 기존 반복자와는 반대로 이동하는 reverse iterator
	// ++ 연산을 하면 기존 반복자의 -- 호출
	// -- 연산을 하면 기존 반복자의 ++ 호출

	auto it1 = v.begin();
	auto it2 = v.end();

	// reverse_iterator : ++ 을 -- 로 변경하는 adapter
	// 아래 코드에서 first, last 자체는 진짜 반복자 아님
	// ++first : 내부적으로 보관하는 it2 에 대해서 "--it2"
	// --first : 내부적으로 보관하는 it2 에 대해서 "++it2"
	std::reverse_iterator first(it2);
	std::reverse_iterator last(it1);

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

