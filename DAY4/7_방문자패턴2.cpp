#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
//					=> 요소 한개에 대한 연산을 정의 하는 객체.

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 방법 #1. 외부에서 모든 요소를 꺼내서 2배로 한다.
	for (auto& e : s)
	{
		e *= 2;
	}
	
	// 방법 #2. 방문자 패턴을 사용합니다.
	TwiceVisitor<int> tv;
	s.Accept(&tv);			// tv 가 s의 모든 요소를 2배로 합니다.


	ShowVisitor<int> sv;	// 방문하는 요소를 출력하는 방문자
	s.Accept(&sv);


}





