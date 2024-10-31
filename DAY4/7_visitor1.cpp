#include <iostream>
#include <list>
#include <vector>

// visitor 패턴 - 이해하기 어려운 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 
	// 방법 #1. 외부에서 모든 요소를 열거해서 2배로
	// => 원리 : s에서 iterator 를 꺼내서 ++ 로 이동하면서 요소 접근
	// => 핵심 : s의 모든 요소를 외부에서 열거 한것
	for (auto& e : s)
		e = e * 2;

	// 방법 #2. 방문자 패턴을 사용
	TwiceVisitor<int> tv;  // 요소를 2배로 하는 일을 하는 방문자
	s.accept(&tv);		   // s 에 방문자를 방문 시킵니다.

}





