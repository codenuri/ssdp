#include <iostream>

// 가상함수의 호출의 정확한 원리

class Animal
{
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
	void f4() {}
};

class Dog : public Animal
{
public:
	virtual void f2() {}
};
int main()
{
	Animal a;
	Dog d;
	Animal* p = &d;

	p->f2();
}














