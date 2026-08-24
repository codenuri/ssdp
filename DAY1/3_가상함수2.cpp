#include <iostream>

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	// #1. 아래 코드는 문제 없는 코드
	// Derived d;

	// #2. 아래 코드도 문제 없는 코드
//	Derived* p = new Derived;
//	delete p;

	// #3. 아래 코드가 이번 예제의 핵심
	Base* p = new Derived;
	delete p;	// Derived 소멸자가 호출 안됨

	// "delete p"
	// 1. 소멸자 호출
	// 2. p가 가리키는 메모리 해제

	// 소멸자 호출을 생각해 봅시다.
	// "p->소멸자()" 이므로 함수 호출의 과정입니다
	// 1. 컴파일러는 p의 대상체 타입은 모르고 p 자체가 Base* 인것만 알고 있다
	// 2. Base 클래스 선언을 보고 소멸자가 가상함수인지 조사
	//   => Base 소멸자가 가상이 아니면 : static binding 하므로 ~Base()호출
	//   =>              가상이면 : dynamic binding 하므로 객체 조사후 소멸자호출
}	
