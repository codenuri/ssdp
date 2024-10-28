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
//	Derived d; // ok. 아무 문제 없는 코드

//	Derived* p = new Derived; // 이순간 생성자 호출
//	delete p;				  // 이순간 소멸자 호출
							  // ok. 아무 문제 없는 코드

	// 그런데, 아래 코드가 핵심입니다.
	// => 실행해서 결과 확인해 보세요
	Base* p = new Derived;
	delete p;
}	
