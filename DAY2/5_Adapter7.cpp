#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #2. 상속이 아닌 포함

template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};
int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	s.push_front(0); // error. push_front() 함수 없음. 

}

// 참고
// => 기반 클래스 함수를 외부 노출 안하려면 "포함" 하면 되는데
// => 왜 private 상속을 사용하나요 ??

class stack : private list {};
				// => 상속이므로 list 가상함수를 override 할수 있다.
class stack
{
	list c;	// => 포함은 list 가상함수를 override 할수 없다.
};

// 현재 예제는 포함이 좋습니다.
// => stack 은 list 의 일부 기능만 내부적으로 사용
// => 외부 노출할필요없으므로