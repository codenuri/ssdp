#include <iostream>
#include <vector>
#include <list>


// Iterator 만들기 #1. Java 스타일의 반복자를 만들어 봅시다
// => 아래 코드는 실행되지 않은 설명을 위한 코드

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// #1. 모든 컬렉션에서 반복자를 꺼낼때는 iterator() 함수를 사용합니다
	// => 모든 컬렉션이 지켜야 하는 "인터페이스가 있고 iterator() 함수를 약속"
	auto it1 = s.iterator();
	auto it2 = s.iterator();

	// #2. 모든 iterator 는 사용법이 동일해야 한다
	// => 모든 iterator 가 지켜야 하는 규칙을 가진 인터페이스가 있을것이다.
	// => 인터페이스안에 "hasNext(), next()" 가 약속되어 있다
	while (it1.hasNext())
	{
		// it1.next() : 현재 요소를 반환하고, 자신은 다음으로 이동
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
