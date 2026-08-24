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

	// #2.
	Derived* p = new Derived;
	delete p;

}	
