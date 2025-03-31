#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// 함수 오버라이드(override)
	// => 기반 클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Dog d;
	Animal* p = &d; 

	p->cry();
}

// p->cry() 를 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(function binding) 이라고 합니다.
// => 객체는 Dog, 포인터 p의 타입은 Animal*

// 1. static binding


// 2. dynamic binding

