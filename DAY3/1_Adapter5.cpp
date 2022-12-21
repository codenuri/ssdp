#include <iostream>
#include <list>
#include <vector>
#include <deque>

// stack 사용시, 내부 컨테이너를 "템플릿 인자"로 변경할수 있게 합니다.

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()              { return c.back(); }
};

#include <stack> // 이 안에 있는 C++표준 stack 이 위 처럼 만들어져 있습니다.
				// 흔히 "stack adapter" 라는 용어를 사용합니다
int main()
{
//	std::stack<


	stack<int> s1;  // 내부적으로 std::deque 에 보관

	stack<int, std::list<int>>   s2;  // list 를 stack 처럼 사용하겠다는것
	stack<int, std::vector<int>> s3;

	s1.push(10);
}
