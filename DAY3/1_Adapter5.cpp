#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속을 사용한 stack adapter
template<typename T> 
class stack : public std::list<T>
{
public:
	// 아래 3개의 함수가
	// 기존 함수 이름을 stack 처럼 보이게 변경한것
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	auto n = s.top();

	s.push_front(5); // 사용자가 이렇게 사용하면 스택이 잘못된 상태가 된다
					 // 위와 같은 상속을 사용한 stack adapter 는 나쁜 디자인
					 // java 의 stack 이 위와 같이 되어 있다
					 // => 그래서 java 진영에서는 "stack 은 사용하지 말라" 라고 배운다
} 
