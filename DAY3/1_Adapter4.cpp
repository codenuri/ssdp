#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter


int main()
{
	// C++ 표준에는 linked list 가 이미 있습니다.
	std::list<int> s;

	s.push_back(10);
	s.push_front(10);

	// 그런데 사용자가 stack 을 요구합니다.
	// => stack 도 C++ 표준에 있지만 없다고... 가정..

	// stack 을 만드는 방법 
	// 1. 새롭게 stack 클래스를 만들고 모든 기능을 직접 구현하자
	// 2. linked list 의 함수 이름만 변경해서 stack 처럼 보이게 하자- adapter
	// 
}
