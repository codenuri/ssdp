#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter 패턴으로 컨테이너의 이름을 Stack 처럼 변경
// 어떤 선형 컨테이너를 사용할것인가는 Policy Base Design 으로 교체 가능하도록 설계
// => 아래 코드가 C++ 표준의 stack 과 동일!
// => <stack> 헤더 안에 있는 코드

template<typename T, typename C = std::deque<T> >
class stack
{
//	std::list<T> c;
	C c;
public:
	void push(const T& e)	{ c.push_back(e); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};
int main()
{
	stack<int, std::list<int>>   s1; // list 를 stack 처럼 사용하겠다는것
	stack<int, std::vector<int>> s2; // vector 를 stack 처럼 사용하겠다는것
	
	stack<int> s;
	s.push(10);
	s.push(20);

	auto n = s.top();
}
