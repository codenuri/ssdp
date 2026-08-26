#include <iostream>
#include <list>
#include <vector>
#include <deque>


// public 상속 : 기반 클래스 기능을 파생 클래스가 모두 사용하고 싶을때
//				 => 기능과 인터페이스 모두 상속
// 

// private 상속 : 기반 클래스의 모든 멤버를 private 으로 상속하겠다는 것
// => 구현은 물려 받지만(stack 이 내부에서 list 기능 사용)
// => 인터페이스는 물려 받지 않겠다(stack 객체로 list 기능을 외부 노출하지 않겠다)

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

	s.push_front(5); // error. private 상속이므로
					 // list 의 모든 멤버 함수는 stack 객체를 사용해서는
					 // 호출 할수 없다 (private 멤버)
}
