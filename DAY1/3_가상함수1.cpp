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
	Animal a;	a.cry();	// #1. animal cry
	Dog d;		d.cry();	// #2. dog cry

	Animal* p = &d; 
		
	// 실제 객체는 "Dog"
	// 가리키는 포인터 p는 "Animal*"

	p->cry();	// C++, C# : Animal cry
				// Java, Python, swift, kotlin 등 대부분의 언어 : Dog cry
}

// p->cry() 를 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(function binding) 이라고 합니다.

// 1. static binding : 컴파일러가 컴파일 할때 함수를 결정
//					   핵심 : 컴파일러는 p가 가리키는 곳에 어떤 객체가 있는지
//							  알수 없다. (실행시 변경될수 있으므로)
//					   컴파일러가 아는 유일한 정보는 p자체의 타입이 "Animal*"
//						라는 것만 알고 있다
//					   따라서, 컴파일러가 결정하는 "Animal::cry" 를 호출하도록
//					   기계어 코드 생성
// 논리적이지 않지만 빠르다.
// C++, C#언어의 기본 바인딩 정책

// 2. dynamic binding : 컴파일 시간에는 "p가 가리키는 메모리를 조사" 하는기계어
//					    코드 생성
//						실행시, 메모리 조사히 호출을 결정
//						p가 가리키는 곳에 Dog가 있었다면
//						"Dog::cry" 호출!!!
// 논리적이지만 느리다.(실행시 메모리 조사)
// java, python, swift, kotilin 등의 대부분의 객체지향 언어의 정책
// C++, C# 의 가상함수