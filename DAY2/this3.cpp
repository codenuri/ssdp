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

	void(*f2)(int) = &Dialog::close; 
}