#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter 와 policy base design 의 결합

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack<int, std::list<int> > s1;   // list 를 stack처럼 사용하겠다는것
	stack<int, std::vector<int> > s2; // vector 를 stack처럼 사용하겠다는것

	stack<int> s; // std::deque 를 사용하는 스택

	s.push(10);
	s.push(20);
	s.pop();


}
