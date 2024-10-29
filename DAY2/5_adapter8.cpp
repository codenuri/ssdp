#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter 와 policy base design 의 결합

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()			  { return c.back(); }
};

#include <stack> // C++ 표준의 stack 이 위와 동일하게 구현되어 있습니다.
				 // 흔히 "stack adapter" 라고 부릅니다.

int main()
{
	std::stack<int, std::list<int> > s3; // C++ 표준 stack

	stack<int, std::list<int> > s1;   // list 를 stack처럼 사용하겠다는것
	stack<int, std::vector<int> > s2; // vector 를 stack처럼 사용하겠다는것

	stack<int> s; // std::deque 를 사용하는 스택

	s.push(10);
	s.push(20);
	s.pop();


}
