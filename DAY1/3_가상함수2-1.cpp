#include <iostream>

// 핵심 
// => 기반 클래스의 소멸자는 가상함수로 만들어야 한다
// => "가상 소멸자" 라고 불리는 유명한 격언!

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;
	delete p;	

}
