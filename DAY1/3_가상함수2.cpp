#include <iostream>
// 핵심 : "기반 클래스의 소멸자는 반드시 virtual" 이어야 합니다

// virtual 이 아닌 경우
// Base* p = new Derived;
// delte p; // <<===== 이순간에 문제가 됩니다.
//						~Derived 가 아닌 ~Base 만 호출되는 문제
//						이 문제를 해결하려면
//						~Base 는 가상함수 이어야 합니다.

// 구글에서 "C++ core guide line" 검 색
// => 1번째 링크
// => C++ 창시자가 만들고 있는 "C++언어에서 지켜야 하는 규칙"


class Base
{
public:
//	~Base() {}
	virtual ~Base() {} // 가상 소멸자 문법
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // ok. 아무 문제 없는 코드

//	Derived* p = new Derived; // 이순간 생성자 호출
//	delete p;				  // 이순간 소멸자 호출
							  // ok. 아무 문제 없는 코드

	// 그런데, 아래 코드가 핵심입니다.
	// => 실행해서 결과 확인해 보세요
	Base* p = new Derived; // Derived 생성자 호출
	delete p;				// ?? 소멸자 호출

	// 소멸자 호출도 "함수 호출" 과정입니다.
	// => static binding 할지 dynamic binding 할지 결정해야 합니다.

	// static binding : 포인터 타입으로 결정
	// dynamic binding : 실제 메모리에 있는 객체조사후 결정

	// static 으로 할지 dynamic 으로 할지는 
	// 함수 선언부를 보고 virtual 있는지 조사
	// 
	// #1. 컴파일러는 p가 Base*라는 사실만 알수 있다.
	// #2. 그래서 Base 클래스 선언을 조사해서 소멸자가 virtual 인지조사
	// #3. Base 소멸자가
	// virtual 이 아니면 : static binding
	// virtual 이면      : dynamic binding
}	
