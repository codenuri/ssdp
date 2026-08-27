#include <iostream>
#include <vector>
#include <list>

// iterator 패턴
// => "복합객체의 내부 구조를 외부에 노출하지 않고도"
// => "동일한 방식으로 모든 요소에 순차적으로 접근하기 위한 방법을 제공한다"

// 요즘 거의 모든 언어에 있는 개념
// => 대부분 언어의 표준 라이브러리에는 iterator 개념 제공


int main()
{
	// C++ 표준 라이브러리(STL) 이야기
	// 
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
