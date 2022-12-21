#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// 1. STL 에 list 가 이미 있습니다.
// 2. 그런데, 사용자가 stack 을 요구 합니다( stack 도 있지만, 없다고 가정)


// list 의 멤버 함수 이름을 stack 처럼 보이도록 변경하는 클래스(adapter)

// 상속을 사용한 어답터 : list 의 모든 기능을 stack 도 외부 노출하게 된다.
//						현재 디자인에서는 아주 나쁘다!!
//						stk.push_front(10) 는 에러 나와야 한다!!!
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};
*/

// 포함을 사용한 어답터..
// 기존클래스(list)의 기능을 stack 은 외부 노출하지 않는다.
// stack 이 만든 함수만 외부 노출된다
template<typename T> class stack 
{
	std::list<T> c;	// 값 타입 입니다. 클래스 어답터 입니다.
//	std::list<T>* p;// 이렇게 되어야 객체 어답터 입니다.

public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	
//	s.push_front(100); // ?? 이렇게 사용할수 있어야 할까요 ??
}


// 객체 어답터 : 포인터나 참조로 포함.
// 클래스 어답터 : 상속이나, 값 타입으로 포함
//			=> 상속            : 기존 클래스의 인터페이스를 외부에 모두 노출
//			=> 값 타입으로 포함 : 기존 클래스의 인터페이스를 노출 안함