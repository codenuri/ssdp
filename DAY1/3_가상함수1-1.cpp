#include <iostream>

class Animal
{
public:
	// non-virtual : static binding 해달라는 것. 
	//				 컴파일 시간에 호출결정(포인터 타입으로 결정)
	void cry1() { std::cout << "Animal cry1" << std::endl; } 


	// virtual : dynamic binding 해달라는 것
	//			 실행시간에 메모리 조사후 호출 결정(실제 객체 타입에 맞는 호출)
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};


class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }		
	void cry2() { std::cout << "Dog cry2" << std::endl; }
};


int main()
{
	Dog d;		

	Animal* p = &d;


	p->cry1();	
}
