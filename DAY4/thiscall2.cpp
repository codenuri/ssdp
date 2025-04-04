#include <functional> 

class Dialog
{
public:
	void Close1(int a) {}
	static void Close2(int a) {}
};
void foo(int a) {} 

int main()
{
	// #1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없습니다. - this 때문
	// #2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.
	void(*f1)(int) = &foo;				// ok			
//	void(*f2)(int) = &Dialog::Close1;	// error
										// 멤버 함수는 인자로 this 가 추가됨
	void(*f3)(int) = &Dialog::Close2;	// ok

	// #3. 멤버 함수의 포인터를 만들려면 아래 처럼 합니다.
	void(Dialog::*f2)(int) = &Dialog::Close1;


	// #4. 멤버 함수 포인터로 함수를 호출하는 방법
//	f2(10); // error. 객체(this)가 없습니다.

	Dialog dlg;
//	dlg.f2(10); // error. Dialog 에는 f2 라는 멤버가 없습니다.

	// 이때 사용하는 연산자가 .* 연산자(pointer to member) 입니다.
//	dlg.*f2(10);  // 그런데, 연산자 우선 순위 문제로 에러
					// .* 보다 ( 가 우선순위가 높기 때문

	(dlg.*f2)(10); // ok.. 


	// #5. 좋은 해결책이 없을까 ?
	f1(10);  // 일반 함수포인터 사용
	(dlg.*f2)(10); // 멤버 함수 포인터 사용

//	f2(&dlg, 10); // "이렇게 사용하게 하자"라고 C++ 창시자 제안
					// uniform call syntax

	// 위 제안을 채택되지 않고, 대신 아래 함수로 해결
	// => std::invoke 는 C++17 입니다.
	// => <functional>
	std::invoke(f1, 10); // f1(10) 으로 호출해 달라.
	std::invoke(f2, &dlg, 10); // dlg.f2(10) 으로 해달라.
}






