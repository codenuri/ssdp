#include <functional> 

class Dialog
{
public:
	void Close(int a) {}

	static void Close2(int a) {}
};
void foo(int a) {} 

int main()
{
	// 핵심 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없다.
	// 핵심 2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 없다.
	void(*f1)(int) = &foo;	// ok			
//	void(*f2)(int) = &Dialog::Close; // error. 멤버 함수는 this가 추가된다.
	void(*f3)(int) = &Dialog::Close2; // ok.. 


	// 핵심 3. 멤버 함수의 주소를 담는 "멤버 함수 포인터" 만드는 방법
	void(Dialog::*f)(int) = &Dialog::Close;


	// 핵심 4. 멤버 함수 포인터로 멤버 함수 호출하기
//	f(10); // error. f 는 멤버 함수를 가리키므로, 객체가 있어야 호출가능합니다.

	Dialog dlg;
//	dlg.f(10);	// error. Dialog 에서 f 라는 멤버를 찾게됩니다.
				// f라는 멤버는 없습니다.

	// "Pointer To Member" 라는 연산자(.*) 를 사용해야 합니다.
//	dlg.*f(10); // error. 연산자 우선순위 문제, 
				// .* 연산자 보다 ( 연산자가 우선순위가 빠릅니다.


	(dlg.*f)(10);	// ok.. 이 표기법이, 멤버 함수 포인터를 가지고
					// 멤버 함수를 호출하는 표기법 입니다
}






