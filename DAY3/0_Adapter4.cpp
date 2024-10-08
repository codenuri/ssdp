#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// 1. STL 에는 list 가 있습니다.
// 2. 그런데, 사용자가 stack 을 요구합니다.(물론 stack 도 있지만 없다고 가정)

// list 의 인터페이스(함수이름)을 변경해서 stack 처럼 보이게 해봅시다.

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); };

	void pop() { std::list<T>::pop_back(); };
	T&   top() { return std::list<T>::back(); };
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(0); // 사용자가 이렇게 사용하면 ???
					 // 사용할수 없게 해야 합니다.
					// 해결책은 다음 소스에서.. 
}


// java 의 스택이 vector 에서 상속 받게 되었습니다.
// => 그래서 stack 과 관련 없는 함수도 많이 있습니다.
// => 안좋은 디자인은 대표적인 예제.. 

