#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속을 사용한 stack adapter
template<typename T> 
class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	auto s = s.top();
} 
