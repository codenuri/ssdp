// 3_가상함수2-2
#include <iostream>

// 모든 기반 클래스의 소멸자는 "반드시 가상함수" 이어야 합니다.
// => 가끔. 고급 기법으로 가상함수 아닌 protected 소멸자로 해결하기도 합니다.
// => Base 내부에 다른 가상함수가 한개도 없는데, 소멸자 때문에
//    가상함수 사용시 생기는 오버헤드를 제거하기 위해

class Base
{
	// 의도 : Base* 인채 로는 delete 하지는 말라는 의미.
	//       delete 시에 컴파일 에러.
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

//	delete p;	// error
	delete static_cast<Derived*>(p);	// ok


}
