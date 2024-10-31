#include <iostream>
#include <vector>
#include <list>

// 반복자(iterator)
// => 복합객체의 내부구조를 노출하지 않고
// => 서로다른 구조의 복합객체를
// => 동일한 방법으로 순차적으로 접근하기 위한 방법을 제공한다.
// => 대부분의 언어에서 이 패턴을 지원

int main()
{
	// 1. list 와 vector 의 메모리 구조를 다릅니다.
	std::list<int>   s = { 1,2,3,4,5 };
	std::vector<int> v = { 1,2,3,4,5 };

	// 2. s, v 의 모든 요소를 "동일한 방법" 으로 접근할수 없을까요 ?

	auto p1 = s.begin(); // p1 은 s의 1번째 요소를 가리키는 반복자객체
	auto p2 = v.begin(); // p2 은 v의 1번째 요소를 가리키는 반복자객체

	// 3. p1 과 p2 는 사용법이 동일합니다.
	++p1;
	++p2;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}
