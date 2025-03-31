#include <iostream>

class Animal
{
public:
	// non-virtual : 기본 바인딩인 static binding 수행
	void cry1() { std::cout << "Animal Cry1" << std::endl; }

	// virtual : dynamic binding 해달라는 의미
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};

int main()
{
	Dog d;
	Animal* p = &d;

	p->cry1();	// static binding. 포인터 타입으로 결정
	p->cry2();	// dynamic binding. 객체 타입으로 결정(실행시간 조사)
}


