#include <iostream>

// "가상 소멸자" 이야기 
// 아주 중요한 문법
// 반드시 알아야 합니다.

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
//	Derived d;	// ok. 아무문제 없는 코드

//	Derived* p = new Derived;
//	delete p;	// ok. 아무문제 없는 코드

	// 아래 코드가 문제입니다.
	Base* p = new Derived;	// 1. sizeof(Derived) 크기의 메모리 할당
							// 2. 생성자 호출

	delete p;	// 1. 소멸자 호출 ( p->소멸자() )
				// 2. 메모리 해지

	// "p->소멸자()" 에서 소멸자도 결국 함수입니다.
	// #1. static binding 할지 dynamic binding 할지 결정해야 합니다.

	// #2. "delete p" 에서 컴파일러는 p가 가리키는 객체의 타입을 알수없고
	//     p 자체의 타입이 Base* 라는 것만 알수 있습니다.

	// #3. 따라서, "Base 클래스 선언"을 보고 소멸자가 virtual 인지 아닌지
	//     를 조사하게 됩니다.

	// => Base의 소멸자가 non-virtual : static binding 하므로
	//									포인터 타입으로 소멸자 결정
	//									Base 소멸자 호출됨.

	// => Base의 소멸자가 virtual : dynamic binding 하므로
	//							실행시간 메모리 조사후 소멸자 결정
	//							객체가 Derived 이므로 Derived 소멸자호출
}	
