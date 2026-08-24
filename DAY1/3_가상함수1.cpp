#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } // 1
};
class Dog : public Animal
{
public:
	// 함수 override : 기반 클래스 함수를 파생 클래스가 다시 만드는 것
	void cry() { std::cout << "Dog Cry" << std::endl; }		// 2
};
int main()
{
	Animal a;  a.cry(); // Animal::cry 호출
	Dog d;	   d.cry(); // Dog::cry 호출

	Animal* p = &d; 

	// 핵심 
	// p       : Animal*
	// p 대상체 : Dog 
	
	p->cry(); // 어느 함수를 호출할까 ?
			  // => 언어의 설계자라면 어떤 함수를 호출하게 할까 ?
}


// p->cry() 를 어떤 함수와 연결할것인가 ?
// => "함수 바인딩" 이라는 주제


// 1. static binding : 컴파일 시간에 컴파일러가 함수 호출을 결정하는 것
//					   컴파일러는 p 자체의 타입이 "Animal*" 라는 것을 알지만
//					   p의 대상체가 어떤 타입인지 알수 없다
//						그래서 컴파일러가 함수를 결정하면 포인터 타입으로 결정
//						Animal::cry 호출
// 빠르지만, 논리적이지 못하다
// C++ 과 C# 기본 바인딩

// 2. dynamic binding : 실행시간에 어느 함수를 호출할지 결정하는 것
//						"p->cry()" 를 컴파일할때
//						1. p가 가리키는 메모리를 조사하는 기계어 코드를 생성하고
//						2. 조사 결과에 따른 함수를 호출하는 기계어 코드 생성
//						실행시 위 기계어 코드가 실행되어서 함수 결정
//						p의 대상체가 Dog 였다면 Dog::cry() 호출
// 느리지만, 논리적이다
// Java, Python, Objective-C, Swift 등 대부분의 객체지향 프로그래밍 언어의 방식
// "C++, C#" 의 virtual function