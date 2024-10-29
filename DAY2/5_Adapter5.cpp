#include <iostream>
#include <list>
#include <vector>
#include <deque>

// stack 을 새롭게 만들려면 많은 작업이 필요 합니다.
// list 의 함수 이름만 변경해서 stack 처럼 보이게 해 봅시다.

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();
}
