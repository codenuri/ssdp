#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준 라이브러리인 STL 에는 이미 list가 있습니다.
// 2. 그런데, stack 이 필요합니다.(이미 있지만 없다고 가정)

int main()
{
	// 방법 #1. 스택 없어도 된다. list 를 한쪽으로만 사용하면 된다.
	std::list<int> s;

	// list를 뒤쪽으로만 삽입/삭제
	s.push_back(10);
	s.push_back(20);

	s.pop_back();
}
