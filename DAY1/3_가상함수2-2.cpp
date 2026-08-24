#include <iostream>


// 기반 클래스 소멸자를 "virtual" 하지 않은 경우
// 1. 파생 클래스 소멸자가 하는 일이 없으면 "문제되지 않음"
//    => 소멸자 필요없으므로

// 2. 소멸자가 하는 일이 있어도 "delete base_type*" 의 코드만 없으면
//    문제되지 않습니다.

// 위 1, 2 에 해당하면 "가상 소멸자" 사용하지 않아도 됩니다

// 그런데, 미래에 코드가 수정될수도 있으므로
// 따라서, 안전한 코드를 작성하려면 

// 방법 #1. 기반 클래스의 소멸자는 항상 "virtual" 로 만들자
// 방법 #2. "delete base_type*" 처럼 사용 못하게 하자- 사용시 컴파일 에러
//		    => Base 소멸자를 protected 에 작성

// C++ 격언
// => "기반 클래스의 소멸자는 
//    public virtual 이거나 protected non-virtual" 이어야 한다

// 구글 "C++ core guidelines" 검색

class Base
{
	// protected 소멸자 : 외부에서 호출하는 코드가 있으면 컴파일 에러
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
//	delete p;	// 컴파일 에러
	delete static_cast<Derived*>(p);

}
