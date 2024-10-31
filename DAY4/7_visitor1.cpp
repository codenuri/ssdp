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
	// =>       iterator 가 없으면 다른 방법으로
	for (auto& e : s)
		e = e * 2;

	// 방법 #2. 방문자 패턴을 사용
	// => 외부에 열거하는 코드는 없다!! 
	// => 컨테이너 내부에서 열거(다음예제)
	TwiceVisitor<int> tv;  // 요소를 2배로 하는 일을 하는 방문자
	s.accept(&tv);		   // s 에 방문자를 방문 시킵니다.

	ShowVisitor<int> sv;   // 요소를 출력하는 일을 하는 방문자
	s.accept(&sv);

	// 규칙 #1. accept 는 모든 종류의 방문자를 받아야 한다.
	// => 모든 방문자의 공통의 인터페이스 필요

	// 규칙 #2. list 뿐 아니라 vector, set, map 에는 accept 가 있어야한다.
	// => 모든 컨테이너는 accept 가 있어야 한다.
	// => 컨테이너의 공통의 인터페이스가 필요 하다.
}





