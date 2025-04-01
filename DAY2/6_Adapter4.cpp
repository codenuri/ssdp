#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// C++ 표준에 list가 이미 있는데, 사용자가 stack 을 요구 합니다.
// (stack 도 있지만 없다고 가정)

template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& e)	{ std::list<T>::push_back(e); }
	void pop()				{ std::list<T>::pop_back(); }
	T& top()				{ return std::list<T>::back(); };
}
int main()
{
	stack<int> s;
	s.push(10);

	// 위 설계의 단점. 아래 코드처럼 사용한다면 ???
	s.push_front(20);
}
