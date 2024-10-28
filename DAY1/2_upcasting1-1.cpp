#include <iostream>

class Animal
{
public:
	int age;
	virtual void cry() {} // 가상함수가 있으면
						  // 가상함수 테이블이 생기고
						  // 테이블 안에 타입정보 기록
						  // dynamic_cast 사용가능
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Animal a;
	Dog    d;

//	Animal* p = &d;
	Animal* p = &a;
	
//	p->age = 10;   // ok
//	p->color = 10; // error

	// Animal* 인 p 를 가지고 Dog 고유 멤버에 접근하려면
	// Dog* 로 캐스팅해야 합니다.
	 
	// static_cast : 컴파일 시간 캐스팅.! 실행시 오버헤드 없음
	//				 컴파일 시간에는 p가 가리키는 곳을 조사할수 없음.
	//				 실행할때 변경될수 있으므로!!
	//				 그래서 아래코드는 무조건 성공
	Dog* dog = static_cast<Dog*>(p);

	std::cout << dog << std::endl;

//	dog->color = 10; // 만일 p가 가리키던 곳이 Dog 가 아니면
					// 이 코드는 잘못된 코드
					// 실행시 비정상종료 될수 있습니다.

	// #2. dynamic_cast : 실행시간 캐스팅
	//					  실행시간에 p가 가리키는 곳을 조사해서
	//					  Dog가 아닌 경우 0 반환

	// 그런데, dynamic_cast 를사용하려면 "객체 어딘가에 타입정보를 기록해야한다."
	// C++은 가상함수 테이블에 기록
	// 따라서, dynamic_cast는 가상함수가 있는 타입만 가능

	Dog* dog2 = dynamic_cast<Dog*>(p);

	std::cout << dog2 << std::endl;


}











