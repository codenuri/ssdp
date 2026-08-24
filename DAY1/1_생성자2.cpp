// 생성자1.cpp - 3page
#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
class Base
{
public:
	Base(int a) {  }
};
class Derived : public Base
{
public:
	// 핵심#1 : Base 에는 디폴트 생성자(인자 없는 생성자)가 없습니다
	// 사용자 코드			// 컴파일러가 변경한 코드
//	Derived()      { }		// Derived()      : Base() { }
//	Derived(int a) { }		// Derived(int a) : Base() { }
		
	// 핵심 #2. 기반 클래스에 디폴트 생성자가 없다면
	//			파생 클래스의 생성자 만들때 반드시 기반 클래스의 
	//			다른 생성자를 명시적으로 호출해야 합니다
	// => 즉, Derived 를 만들때 Base 에 디폴트 생성자가 없다는 것을
	//    반드시 알고 있어야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{
}
