class Dialog
{
public:
	void close(int code) {}

	static void close2(int code) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok 	
	void(*f2)(int) = &Dialog::close; // error. 멤버 함수이므로 this 추가된 함수

	void(*f3)(int) = &Dialog::close2; // ok. static 멤버 함수는 this가 추가안됨.

	// 1. 일반함수 포인터에 멤버 함수의 주소를 담을수 없습니다.
	// 2. 일반함수 포인터에 static 멤버 함수의 주소를 담을수 있습니다.

	// 참고) 멤버함수 주소는 "멤버 함수포인터" 라는 문법이 있습니다.
	void(Dialog::*f4)(int) = &Dialog::close; // ok
}