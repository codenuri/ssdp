#include <iostream>
#include <list>
#include <vector>
#include <deque>

// private 상속과 포함은 유사해 보입니다.
// => 메모리사용량, 성능
// => 기반 클래스 인터페이스 노출안함 등..

// private 상속 : 기반 클래스의 가상함수를 override 할수 있는 능력이 있습니다.
// 포함         : 상속이 아니므로 가상함수 override 안됩니다.

// 사용자 측면에서 "에러 메세지"등을 고려한다면
// private 상속 보다 포함이 좋은 경우가 더 많습니다.


// private 상속 : 기반 클래스 멤버를 물려 받을때
//				  모든 멤버의 접근지정자를 private 변경해서 물려 받겠다는것
//				  구현은 물려받지만(stack 이 내부적으로는 사용)
//				  인터페이스는 물려 받지 않겠다(list 함수를 외부 노출 안함)
template<typename T> class stack1 : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

template<typename T> class stack2
{
	std::list<T> c;	
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack1<int> s1;
	stack2<int> s2;
	
	s1.push_front(10); // error. 이유는 private 이므로
	s2.push_front(10); // error. 이유는 함수가 없다.
					// => 사용자 측면에서는 "함수가 없다"가 좋습니다!
}
