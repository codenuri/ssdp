#include <iostream>

class Animal
{
public:
	// non-virtual : 아래 함수 호출시 기본 바인딩인 static binding 사용
	// => 대상체가 아닌 포인터 자체의 타입으로 함수 결정
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : 아래 함수 호출시는 dynamic binding 으로 해달라는 것
	// => 포인터 타입이 아닌 포인터가 가리키는 대상체를 조사해서
	//    함수를 결정해 달라는 것
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
	p->cry1();	// static binding : 포인터 타입으로 함수 결정, Animal::cry
	p->cry2();  // dynamic binding : 대상체 조사해서 함수결정, Dog::cry
}
