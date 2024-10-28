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
	// #1. 가상함수 override 할때 "virtual" 은 있어도 되고  없어도 됩니다.
	virtual void foo() {} // 이 코드와
//	void foo() {} // 이 코드는 완전히 동일


	// #2. 가상함수재정의시 실수(오타)가 있어도.. 
	// => 에러가 아닙니다.
	// => 다른 함수를 추가한것
//	virtual void fooo() {}
//	virtual void goo(double){}


	// #3. 위 문제가 많은 버그의 원인이 되었습니다.
	// 그래서, C++11 에서 "override" 키워드 추가
	virtual void fooo()      override {}  // 새로운 함수가 아닌
	virtual void goo(double) override {}  // override 하는 것이라고 알려주는것
};

int main()
{
}





