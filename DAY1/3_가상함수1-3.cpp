#include <iostream>


class Animal
{
	int age;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
	void f4() {}
};

class Dog : public Animal
{
	int color;
public:
	virtual void f2() {}
};
//------------------------------------------
int main()
{
	Animal a1, a2;
	Dog d;
	Animal* p = &d;

	p->f2();


}














