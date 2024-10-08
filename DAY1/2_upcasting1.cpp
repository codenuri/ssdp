﻿// 7 page

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog d;

	Dog* p1 = &d;		// ok
	int* p2 = &d;		// error

	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 객체를 가리킬수 있다.
	// => upcasting 이라고 합니다.
	// => 가능한 이유는 "메모리 그림"을 생각해 보세요
	
	Animal* p3 = &d;	// ok. 

	// 핵심 #2. 컴파일러는 "p3"가 가리키는 곳에 실제 어떤 종류의 객체가 
	// 있는지 알수 없습니다.
	// => 컴파일러가 아는 것은 "p3" 자체의 타입이 "Animal*" 라는 것만 알수있다
	// => 아래 코드를 생각해 보세요
	// if (사용자 입력 == 1) p3 = &a; 


	// 핵심 #3. static type check
	// => Animal* 인 p3로는 Animal 자체의 멤버만 접근 가능합니다.
	// => Dog 고유의 멤버를 접근할수 없습니다.

	// static type check : 컴파일 할때 타입을 확인하는 것
	// dynamic type check : 실행할때 타입을 확인하는 것
	//						(파이썬)

	p3->age = 0; // ok
//	p3->color = 0; // C++, C#, java : 컴파일 에러
					// Python : 컴파일은 ok. 실행시에 color가 없으면
					//			예외 발생.

	// 핵심 #4. p3로 Dog 고유의 멤버에 접근하려면
	//          캐스팅해야 합니다.

	static_cast<Dog*>(p3)->color = 10; // ok. 
		// => 단 이경우는 p3 가 Dog 를 가리킨다는 확신이 있어야 합니다.
		// => Dog 객체가 아닌 경우는 "undefined, 미정의 동작 발생"

}











