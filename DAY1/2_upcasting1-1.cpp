#include <iostream>

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

//	Animal* p = &d;	
	Animal* p = &a;

	std::cout << p << std::endl;

	// static_cast vs dynamic_cast
	// static_cast : 컴파일 시간 캐스팅
	//				 컴파일러는 p가 가리키는 객체를 조사할수 없다.
	//				 따라서 아래코드는 항상 성공
	//				 반환된 p1으로 color 접근은 잘못된 코드
	Dog* p1 = static_cast<Dog*>(p);

	std::cout << p1 << std::endl;

//	p1->color = 10; // 잘못된 코드.절대 사용하면 안됩니다

	
	// dynamic_cast : 실행 시간 캐스팅
}











