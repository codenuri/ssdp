#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e)	{ c.push_back(e); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); };
}
int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(20); // error. 상속이 아니라 포함이므로
						// list 함수는 이제 사용 못함
}
