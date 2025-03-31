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
	// #1. 가상함수 재정의시, virtual 은 있어도 되고 없어도 됩니다.
//	virtual void foo() {} // ok
//	void foo() {} // ok.  위와 동일


	// #2. 가상함수 재정의시 실수(오타)가 있어도
	// => 에러가 아닙니다.
	// => 컴파일러는 다른 가상함수를 "추가" 했다고 생각하게 됩니다.
//	virtual void fooo() {}
//	virtual void goo(double){}

	// #3. #2 같은 현상때문에 버그가 너무 많았습니다.
	// => 이문제를 해결하기 위해 C++11 에서 "override" 키워드 도입
	// => 새로운 함수가 아니라, override 하는 것이라고 알려주는것
	// => 동일한 함수가 기반 클래스에 없으면 컴파일 에러
	virtual void fooo() override  {}		// error
	virtual void goo(double) override  {}	// error

	// 이시간 이후의 모든 예제에서는 "override" 사용합니다.

};

int main()
{
}





