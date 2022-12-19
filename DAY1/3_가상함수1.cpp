#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 
};
int main()
{
	Animal a;
	Dog d;
	Animal* p = &d; 

	if ( 사용자가 입력한 값 == 1) p = &a;

	// 위 코드는 실행시 p가 가리키는 객체를 변경합니다.
	// => 따라서, 컴파일러는 p가 가리키는 객체가 무엇인지는 절대 알수 없습니다.

	// 실제객체    : Dog
	// 포인터 타입 : Animal*
	p->cry1();		// 논리적으로 당연히 "Dog cry1" 가 맞는 동작입니다.
}

// p->cry1() 을 어떤 함수로 연결할것인가 ?
// => 함수 바인딩(function binding) 이라고 합니다.

// 1. static binding : 컴파일 시간에 컴파일러가 어느 함수를 호출할지 결정
//					   컴파일러는 컴파일 시간에는 p가 가리키는 객체가 무엇인지
//						알수 없습니다.
//						오직, 알고 있는 정보는 p가 "Animal*" 라는것!!!
//						따라서, 컴파일러가 함수 호출을 결정하면
//						Animal cry1 호출.!
// 빠르지만, 비 논리적.
// C++/C#언어의 기본 바인딩 정책

// 2. dynamic binding : 컴파일 시간에는 p가 가리키는 메모리를 조사하는 기계어코드
//						생성. 실행시간에 메모리 조사후 어떤 함수 호출할지 결정
//						p가 가리키는 객체가 Dog 라면 Dog cry1 호출
// 느리지만 논리적
// java, python, kotlin, swift 등의 대부분의 객체지향 언어
// C++/C#의 가상(virtual)함수!



