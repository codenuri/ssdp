// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 가상 함수 문법 정리
	// #1. override 할때는 virtual 생략가능
//	virtual void foo() {}
//	void foo() {}  // 위와 동일


	// #2. 가상함수 override 시 실수(오타)가 있어도
	// => 에러가 아니라 새로운 함수를 만든것
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. 위와 같은 문제를 해결하기 위해
	// C++11 부터 "override" 키워드 도입
	// => 새로운 함수가 아닌 override 한다고 컴파일러에게 알리는것
//	void fooo() override {} // error
	void foo() override {} // ok
};

int main()
{
}





