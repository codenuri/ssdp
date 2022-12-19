#include <iostream>
// upcasting3.cpp
class Animal
{
public:
	virtual ~Animal() {} // 모든 기반 클래스의 소멸자는 가상함수 이어야 합니다
	int age;
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

void NewYear(Animal* p)
{
	++(p->age);

	// 세월이 지나 요구사항이 생겼다..
	// p가 Dog를 가리키면 색상도 변경하고 싶다

	// 이함수의 인자가 "Animal*" 로 설계되었다는 것은
	// => 이 함수 안에서는 모든 동물의 공통의 작업만 하겠다는 것
	// => 새로운 요구사항이 생기면 새로운 함수를 만드세요
}

void NewYear(Dog* p)
{
	// 기존 NewYear를 다시 호출해서 공통의 작업을 먼저 실행
	NewYear(static_cast<Animal*>(p));

	// 추가 요구사항 실행
	p->color = 10;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);

}











