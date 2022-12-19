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
	// 핵심 1. 가상함수 재정의시 
	// => "virtual"은 붙여도 되고 빼도 됩니다.
	// => 하지만, 붙이는 것이 가독성에 좋습니다.
	// virtual void foo() {}

	// 핵심 2. 가상함수 재정의시 오타(실수)가 있으면
	// => 에러가 아닌 새로운 가상함수로 취급 됩니다.
	// => 이문제가 너무 심각해서 C++11 에서 "override" 가 나왔습니다.
	virtual void fooo() {}
	virtual void goo(double){}
};

class Derived2 : public Base
{
public:
	// 핵심 3. 가상함수 재정의시 되도록이면 "override" 붙이세요
	// => 새로운 가상함수가 아니라, 재정의하고 있다고 컴파일러에게 알리는것
	// => 오타 발생시, 컴파일 에러.
	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





