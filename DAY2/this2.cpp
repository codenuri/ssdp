class Dialog
{
public:
	void close(int a) {}
	static void close2(int a) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo; // ok

	void(*f2)(int) = &Dialog::close; // error. close 는 인자가 한개가 아닙니다
										// this 가 있습니다. 그래서 error
	void(*f3)(int) = &Dialog::close2; // ok. static 멤버 함수는 this 없음.

	// 핵심 :
	// 1. 멤버 함수의 주소를 일반 함수 포인터에 담을수 없다.
	// 2. static 멤버 함수의 주소를 일반 함수 포인터에 담을수 있다.
}