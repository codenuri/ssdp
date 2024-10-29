#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #1. private 상속
// private 상속 : 기반 클래스의 모든 멤버를 private 영역에 상속해 달라.
// public 상속 : 접근속성을 변경하지 말라.
template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()			  { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(0); // error. private 상속이므로
					 // private 멤버

}
