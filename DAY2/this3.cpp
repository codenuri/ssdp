#include <functional> // std::invoke 를 위한 헤더

class Dialog
{
public:
	void close(int a) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo; // ok
	
	// 핵심 #1. 멤버 함수의 주소를 담는 포인터 만들기

	void(Dialog::*f2)(int) = &Dialog::close; 


	// 핵심 #2. 멤버 함수 포인터로 호출하는 방법
	
//	f2(5);	// error. 멤버 함수는 "객체.함수(인자)" 가 되어야 하는데.
			// 객체가 없습니다.

	Dialog dlg;
//	dlg.f2(5); // error. Dialog 클래스 에서f2 검색하는데 f2 는 멤버 아님

	// 이때 필요한 연산자가 "pointer to member" 라는 연산자
	// .*  ->*
//	dlg.*f2(5); // 하지만 연산자 우선순위 문제로 에러
				// .* 보다 ( 가 우선순위가 높아서
				// f2(5) 를 먼저해서 - 이경우 역시 this가 없다

	(dlg.*f2)(5); // ok. 멤버함수 포인터로 멤버함수 호출하기

	//함수 포인터 사용법 정리
	f1(5);	// 일반 함수 포인터 사용
	(dlg.*f2)(5); // 멤버 함수 포인터 사용

	// 사용법이 너무 다르다. 동일하게 사용할수 없을까 ?
	// std::invoke() : C++17
	std::invoke(f1, 5);
	std::invoke(f2, &dlg, 5);
}