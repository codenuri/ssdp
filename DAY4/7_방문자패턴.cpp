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

	// 위 코드의 내부 원리.. 컴파일러가 아래 코드로 변경합니다.
	// => 즉, 반복자가 있는 타입(iterable type) 만 사용가능합니다.
	auto first = s.begin();
	auto last = s.end();

	for (; first != last; ++first)
	{
		auto& e = *first;
		//-----------------------
		e *= 2;
	}


}





