// 가상함수2-1

#include <iostream>

// 1. 기반 클래스의 소멸자는 기본적으로 "virtual" 이어야 합니다.

// 2. 그런데, virtual 함수가 있으면
// => 가상함수 테이블이 메모리에 놓이게 됩니다. - 메모리 사용량 증가
// => 호출시, 메모리 조사때문에 성능저하. 

// 3. 아래 같은 코드가 없다면 소멸자를 "virtual" 로하지 않아도 됩니다.
// Base* p = new Derived;
// delete p; // <== 이코드 

// 4. 3번처럼 사용했을때 컴파일에러나게 해 봅시다.
// => protected 소멸자

class Base
{
protected:
	~Base() {} 
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
	delete p;	// 이순간 가상소멸자가 아니므로 ~Base를 호출해야 하는데		
				// protected에 있으므로 error.
				// 즉, 이렇게 할수 없다.

	delete static_cast<Derived*>(p); // 이코드는 ok. 
									// ~Derived 호출 하므로!!

}
