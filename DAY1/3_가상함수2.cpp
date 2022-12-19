#include <iostream>

// 모든 기반 클래스의 소멸자는 "반드시 가상함수" 이어야 합니다.

class Base
{
public:
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	// 객체 생성. 생성자 호출
//	delete p;					// 객체 파괴. 소멸자 호출.

	Base* p = new Derived;	// 객체 생성. 생성자 호출

	delete p;	// 이순간, 소멸자를 호출해야 하는데. 소멸자도 함수이다.!!
				// 1. static binding 할지, dynamic binding 할지를 결정해야 한다.
				// 2. p가 Base* 이므로 "Base 클래스 선언을 보고, 소멸자가 
				//    가상인지 조사
				// 가상이 아니면 : 포인터 타입인 ~Base() 호출
				// 가상이면      : 메모리 조사후 호출.


}	
