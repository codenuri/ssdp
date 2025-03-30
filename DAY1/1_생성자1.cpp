// 빌드 하는 방법 : Ctrl + F5

// 생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	Derived()		
	{ 
		// call Base::Base() <= 컴파일러가 추가한 코드
		std::cout << "Derived()" << std::endl; 
	}

	Derived(int a)	
	{ 
		// call Base::Base() <= 컴파일러가 추가한 코드는 항상 Base
		//						디폴트 생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}

	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 사용자 코드가 먼저 실행되고 Base 소멸자 호출 코드 추가
		// call Base::~Base()
	}
};
int main()
{
//	Derived d1;
	Derived d2(5);	// call Derived::Derived(int).

}
