#include <iostream>

class Animal
{
public:
	// non-virtual : static binding, 컴파일러가 어느함수를 호출할지 결정
	void cry1() { std::cout << "Animal Cry1" << std::endl; }

	// virtual : dynamic binding, 컴파일 시간에는 메모리 조사 기계어 생성
	//							  실행할때 함수 호출 결정.
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

	// 1. 멤버 함수 호출시, static binding 할지, dynamic binding 할지 결정해야 합니다.
	// 2. 컴파일러는 "p가 Animal*" 라는 것만 알고 있습니다.
	// 3. 따라서, Animal 클래스 선언을 보고, 각 멤버 함수가 가상인지 아닌지 조사합니다
	p->cry1();	// virtual 이 아니므로 컴파일 할때 "call Animal cry1" 확정!!
	p->cry2();  // virtual 이므로 p의 메모리 조사 기계어 코드 생성
				// 실행시 결과에 따라 호출.
}

// godbolt.org : 다양한 언어의 "어셈블리코드(기계어)를 볼수 있는 사이트