#include <iostream>
#include <list>
#include <vector>
#include <deque>


// public 상속 : 기반 클래스 기능을 파생 클래스가 모두 사용하고 싶을때
//				 => 기능과 인터페이스 모두 상속
// 

// private 상속


template<typename T>
class stack : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop() { std::list<T>::pop_back(); }
	T& top() { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	auto n = s.top();

	s.push_front(5);
}
