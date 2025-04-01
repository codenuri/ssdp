// git 에서 메뉴이벤트 3번 복사
#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a) { printf("f1, %d\n", a); }
void f2(int a, int b) { printf("f2, %d, %d\n", a, b); }
void f4(int a, int b, int c, int d) 
{
	printf("f4, %d, %d, %d, %d\n", a, b, c, d);
}

class Dialog 
{
public:
	void close(int a, int b) { printf("Dialog::close, %d, %d\n", a, b); }
};

int main()
{
	// C 함수 포인터 : 유연성이 없습니다
	//				signature가 동일한 함수주소만 담을수 있습니다.
//	void(*f)(int);
//	f = &f1; // ok
//	f = &f2; // error 

	// C++ std::function : 함수 포인터의 일반화 버전

	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10)  => 결국 함수 포인터와 사용법 동일합니다.

//	f = &f2; // error. f2는 인자가 2개...

	// 핵심 : std::function 은 std::bind 의 반환 값을 보관 가능
	//	     즉, 어떤 함수라도, 인자를 1개로 만들면 f에 담을수 있습니다.

	f = std::bind(&f2, 0, _1); // std::bind 결과는 인자가 한개인함수

	f(10); // f2(0, 10);


	f = std::bind(&f4, 9, 3, _1 ,2 ); // ? 채우세요. 한개 아닙니다.

	f(10); // f4(9, 3, 10, 2) 나오게 하세요


	// 멤버 함수 : 객체가 있어야 호출가능
	// => 따라서, std::bind 사용시 2번째 인자로 객체 주소도 전달
	Dialog dlg;
	dlg.close(1, 2);

	f = std::bind(&Dialog::close, &dlg, 0, _1);
	f(10); // dlg.close(0, 10)


	f = [](int a) { std::cout << "lambda\n"; };

	f(10);
}
