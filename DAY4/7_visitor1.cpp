#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 방법 #1. 외부에서 요소를 꺼내서 직접 2배로 변경한다
	for (auto& e : s)
	{
		e *= 2;
	}

	// 방법 #2. 방문자(Visitor) 패턴 사용
	TwiceVisitor<int> tv; // 자신이 방문하는 모든 요소를 2배로 하는 방문자
	s.accept(&tv);	// tv 가 s 의 모든 요소를 방문한다

}





