// 생성자1.cpp - 3page
#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
// 핵심 : Base 클래스에 디폴트 생성자가 없습니다.
class Base
{
public:
	Base(int a) {  }
};
class Derived : public Base
{
public:
	// #1. Base 디폴트 생성자가 없는 경우 아래 처럼 만들면 에러가
	//     발생하는 이유를 정확히 알아야 합니다.
	/*
	Derived()      
	{ 
		// call Base::Base()
	}

	Derived(int a) 
	{
		// call Base::Base()
	}
	*/
	
	// #2. 해결책. 사용자가 기반 클래스의 디폴트가 아닌 다른 생성자를
	//     호출하도록해야 합니다.
	// => 초기화 리스트 문법으로 표기
	Derived() : Base(0)
	{
		// call Base::Base(0)
	}

	Derived(int a) : Base(a)
	{
		// call Base::Base(a)
	}

};
int main()
{
}
