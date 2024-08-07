﻿#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거(순회)
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
// => 요소 한개에 대한 연산을 정의하고, 
// => 그연산을 모든 요소에 대해서 적용하는 것


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 방법 #1. 외부에서 모든 요소를 꺼내서 2배로!
	for (auto& e : s)
		s *= 2;

	// 방법 #2. 방문자 패턴
	TwiceVisitor<int> tv; // 요소를 2배로 하는 방문자 객체
	s.accept( &tv );	  // s의 모든 요소 방문


	ShowVisitor<int> sv;  // 요소 한개를 출력하는 방문자
	s.accept( &sv );	  // s의 모든 요소 방문(출력)

	// 규칙 #1. accept() 함수는 다양한 방문자 객체를 받아야 한다
	// => 모든 방문자는 공통의 기반 클래스 필요
	// => accept(IVisitor* )

	// 규칙 #2. 방문자 패턴을 사용하기로 했다면
	//	        list 뿐아니라 vector, set 에도 accept 가 있어야 한다.
	// => 모든 복합객체는 accept 가 있어야 한다.
	// => 복합 객체의 인터페이스가 필요
}





