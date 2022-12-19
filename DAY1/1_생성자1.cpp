//생성자1.cpp - 3page
#include <iostream>

// 상속에서의 생성자 호출의 정확한 원리
// => 컴파일러가 파생 클래스의 생성자에서 기반 클래스 생성자를 호출하는 코드를
//    추가해 준것
// => 컴파일러는 항상 "기반 클래스의 디폴트 생성자를 호출" 하도록 코드 생성

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:						
	// 사용자 코드		// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  <<== 핵심은 컴파일러가 만든
	{												// 코드는 항상 기반 클래스의
													// 디폴트 생성자를 호출한다는것
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 "~Derived()" 의 제일 아래 부분에 기반 클래스 소멸자 호출 코드 추가
		// ~Base();
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(5)
}
