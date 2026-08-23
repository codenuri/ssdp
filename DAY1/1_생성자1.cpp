// 생성자1.cpp - 3page
#include <iostream>
// 핵심 : 생성자 호출의 정확한 원리를 이해해 봅시다

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
	// 사용자가 만드는 코드	// 컴파일러가 변경한 코드
	Derived()				// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	}
		
	Derived(int a)			// Derived(int a) : Base() // 핵심 : 컴파일러 추가 코드는
	{													// 항상 Base의 디폴트생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{
		std::cout << "~Derived()" << std::endl; 
		
		// 소멸자는 Derived 코드가 먼저 실행되고 기반 클래스 소멸자 호출
		// Base::~Base();
	}
};
int main()
{
//	Derived d1;
	Derived d2(5);

}





// 1. DAY1.zip 압축 풀고
// 2. DAY1.slnx 더블클릭해서 visual stdio 실행
// 3. 소스를 빌드에서 제외/포함하는 방법 알아두세요
// 4. 빌드/실행 하는 법 : Ctrl +F5
// 5. 폰트등 환경설정 변경하려면 
//    - "도구" 메뉴, "옵션" 메뉴 선택후 "환경" 에서 폰트 변경가능
