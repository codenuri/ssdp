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

	Derived* p = new Derived;
	delete p;

}	
