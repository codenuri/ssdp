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
	f2(10);//?
}






