#include <iostream>






int main()
{
	// 일반적으로 컨테이너의 내부 메모리 구조에 따라 
	// 모든 요소를 열거하는 방법은 다릅니다.
	slist<int> s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리
	vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리

	// 반복자(iterator) 패턴
	// => 컨테이너의 내부 구조에 상관없이 동일한 방법으로 모든 요소를 열거
	//    할수 있게 하자는 패턴
	// => 열거자(enumerator) 라고도 합니다.

	// 목표
	slist_enumerator  p1 = s.get_enumerator();
	vector_enumerator p2 = v.get_enumerator();

	int n = p1->get_object(); // p1 이 가리키는 요소얻기 (1)

	p1->move_next(); // 다음으로 이동

	int n2 = p1->get_object(); // 2 

	// 핵심 1. 모든 반복자(열거자)는 사용법이 같아야 한다.
	// => 인터페이스가 필요 하다.

	// 핵심 2. 모든 컨테이너는 동일한 방법으로 반복자를 꺼낼수 있어야 한다.
	// => 컨테이너의 인터페이스가 필요 하다.
}