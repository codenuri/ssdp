#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } // #1
};

class Dog : public Animal
{
public:
	// function override : 기반클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog cry" << std::endl; }		// #2
};

int main()
{
	Animal a;	a.cry();
	Dog d;		d.cry();

	Animal* p = &d; 

	p->cry();
}


