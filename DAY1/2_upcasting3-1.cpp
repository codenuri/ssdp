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
	// p->color = 10; // error. p는 Animal* !!

	// static_cast : 컴파일 시간(static) 캐스트. p가 가리키는 것이 정말 Dog 인지
	//				 조사하지 않고, 캐스팅. 
	//				=> p가 가리키는 곳이 Dog 라는 확신이 있을때만 사용해야한다
	// Dog* pDog = static_cast<Dog*>(p);

	// dynamic_cast : 실행시간(dynamic) 캐스트.
	//				  실행시간에 p가 가리키는 메모리를 조사후..
	//				  객체가 정말 Dog 일때만 성공..
	//				  Dog가 아니면 0 반환
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	
}











