#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 기반 클래스의 기능을 외부 노출하지 않고
// 파생 클래스에서만 사용한다면
// => "상속" 을 사용하지 말고 "포함"을 사용하는 것이 좋다

// 상속 : 기반 클래스 기능을 외부 노출
// 포함 : 기반 클래스 기능을 파생 클래스 내부에서 사용

// 그럼 private 상속은 왜 사용하나요 ?
// private 상속 : 기반 클래스 기능을 외부 노출안함. list 가상함수 재정의 가능
// 포함         : 포함된 list 기능을 외부 노출안함. 가상함수 재정의 안됨


template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	auto n = s.top();

	s.push_front(5); // error. 이런 멤버 함수는 없다
}
