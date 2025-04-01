#include <iostream>
#include <list>
#include <vector>
#include <deque>
// adapter 패턴으로 설계된 stack 인데.
// policy base design 을 적용해서 성능저하없이 컨테이너(내부자료구조)
// 를 교체할수 있는 디자인.
template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); };
}

#include <stack> // 이 안에 있는 코드가 위처럼 되어 있습니다.
				 // 흔히, C++ 표준의 stack 을 "stack adapter" 라고합니다
int main()
{
	/*
	stack<int, std::list<int>> s1;
	stack<int, std::vector<int>> s2;
	stack<int> s;

	*/
	std::stack<int, std::list<int>> s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int> s;

	s.push(10);
}
