#include <iostream>
#include <vector>
#include <list>

int main()
{
	// 1. list 와 vector 의 메모리 구조를 다릅니다.
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 2. s, v 의 모든 요소를 "동일한 방법" 으로 접근할수 없을까?
	// => 반복자(iterator) 를 사용하면 됩니다.
	auto p1 = s.begin();
	auto p2 = v.begin();

	// 3. p1 과 p2 는 사용법이 동일합니다.
	++p1;
	++p2;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}
