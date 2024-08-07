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
	Dog d;
	Dog* p1 = &d; // ok
	
//	int* p2 = &d; // error
	
	// 핵심 #1. 파생클래스 객체의 주소를 "기반 클래스 포인터" 에 담을수 있다.
	// => upcasting 이라고 합니다.
	// => 이유는 "메모리 그림"을 생각해 보세요
	// => "Dog" 객체의 메모리 위쪽에는 "Animal" 모양으로 되어 있다.
	Animal* p3 = &d; // ok


	// 핵심 #2. 기반 클래스 포인터로는 "기반 클래스 멤버" 만 접근 가능합니다.
	// => 이유는 "p3 가 가리키는 곳은 실행시간에 변경"될수도 있습니다.
    //	  if (사용자입력 == 1) p3 = new Animal;

	// => 그래서, 컴파일러는 p3 가 가리키는 곳이 어떤 객체인지 알수 없습니다
	//    (실행시간에 바뀔수 있으므로)

	// => 컴파일러는 p3 가 가리키는 곳이 실제 어떤 객체인지는 모르고, 
	//    p3의 타입이 "Animal*" 라는 것만 알수 있습니다.

	// 그래서 p3로는 Animal 의 멤버만 접근 가능.
	p3->age   = 10; // ok
	p3->color = 10; // error

	// 핵심 #3. p3 를 사용해서 Dog 고유의 멤버에 접근하려면
	// => 컴파일러에게 "p3가 가리키는 곳은 Dog 가 맞다" 고 알려주어야 합니다.
	// => 이런 과정이 "캐스팅" 입니다.

	static_cast<Dog*>(p3)->color = 10;
		// 단, 이경우는 p3가 가리키는 곳이 Dog라는 확신이 있어야 합니다.
		// Dog 가 아니라면 "undefined", 대부분 잘못된 메모리 접근

	// 핵심 #4. p3가 가리키는 곳이 Dog 인지 조사할수 없나요 ?
	// => dynamic_cast 사용. 다음예제에서. 
}











