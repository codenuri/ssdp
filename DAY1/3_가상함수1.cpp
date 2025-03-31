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

// 1. static binding ( early binding )
// => 컴파일 시간에 컴파일러가 어떤 함수를 호출할지는 결정
// => 핵심 : 컴파일러는 "p가 가리키는 객체의 타입"은 알수 없다.
//           단지, p자체의 타입이 Animal* 라는 것만 알수 있다.
//           따라서, Animal cry 호출
// 빠르지만 논리적이지는 않다.
// C++/C#

// 2. dynamic binding( late binding )
// => 컴파일 시간에는 p가 가리키는 곳을 조사하는 기계어 코드를 생성.
// => 실행시간에 메모리를 조사해서 호출을 결정
// => p가 가리키는 곳이 Dog 객체 였다면 Dog cry 호출
// 느리지만 논리적이다.
// java, python, swift, objective-c, kotlin 등의 대부분의 객체지향 언어
// C++/C# virtual 

