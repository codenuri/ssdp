#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// => C++에서는 많이 사용하지 않지만, 중요한 의미를 하나 가진 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 방법 1. for 문사용
	for (auto& e : s)
		e = e * 2;

	// 방법 2. 방문자 패턴을 사용
	TwiceVisitor<int> tv;	// 방문하는 요소를 2배로 하는 방문자
	s.Accept(&tv);			// 방문자가 list 방문

	ShowVisitor<int> sv;	// 방문하는 요소를 화면 출력하는 방문자
	s.Accept(&sv);

	// 핵심 1. 방문의 대상(복합객체)는 다양한 방문자를 받아 들여야(Accept) 한다.
	//	=> 모든 방문자는 공통의 인터페이스가 필요 한다.

	// 핵심 2. list 뿐 아니라 vector 등의 복합객체도 방문자를 받아 들이는
	//		   함수가 있어야 한다.
	// => 방문의 대상에는 "Accept" 가 있어야 한다. - 인터페이스 필요

}





