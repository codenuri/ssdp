// 1_생성자1-1.cpp     1번 복사해서 주석 지워보세요

//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
//	Base() { }
	Base(int a) { }
	~Base() { }
};

class Derived : public Base
{
public:
	// 사용자 코드		// 컴파일러가 변경한 코드
//	Derived() {}		// Derived() : Base(){}
//	Derived(int a) {}	// Derived() : Base(){}

	// 1. 기반 클래스에 디폴트 생성자가 없거나
	// 2. 의도적으로 기반클래스의 다른 생성자를 호출하려면
	// => 사용자가 명시적으로 호출해 주어야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}


	~Derived() 	{}
};

int main()
{

}

// 9:30 분에 시작합니다.