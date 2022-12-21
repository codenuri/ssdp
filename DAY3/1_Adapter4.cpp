#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T> class stack1 : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

template<typename T> class stack2
{
	std::list<T> c;	
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top()   { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
}
