#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 아래 코드가 왜 에러인지 생각해 보세요
	// 개발자 코드		// 컴파일러가 변경한 코드
//	Derived() { }		// Derived()      : Base() { }
//	Derived(int a) { }	// Derived(int a) : Base() { }

	// 핵심 1. 기반 클래스에 디폴트 생성자가 없으면
	//         반드시 파생 클래스 생성자에서
	//		  기반 클래스의 다른 생성자를 명시적으로 호출해야 합니다.
		
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{

}
