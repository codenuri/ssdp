// 가상함수2-1

#include <iostream>


class Base
{
public:
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
