#include <iostream>
#include <vector>
#include <list>

int main()
{
	// 아래 코드는 실행안됩니다. 
	// => java 컬렉션(C++용어는 컨테이너) 사용법을 설명하기 위해
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };
	
	// #1. 컬렉션에서 반복자를 꺼낼때는 iterator() 함수 사용
	// => 모든 컬렉션에는 iterator()가 있어야 한다.
	// => 컬렉션의 인터페이스가 필요!
	slist_iterator<int> it1 = s.iterator();
	vector_iterator<int> it2 = v.iterator();

	// #2. 모든 반복자는 사용법이 동일해야 한다.
	// => 반복자의 인터페이스 필요
	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
					// 1. it1 이 가리키는 요소 반환하고
					// 2. it1 은 다음요소로 이동
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
