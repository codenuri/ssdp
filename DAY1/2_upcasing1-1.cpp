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
	Dog d;
	Animal a;
	
	Animal* p = &a; 

	// 현재 p가 가리키는 대상은 Animal !

	// static_cast : 대상체가 Dog 인지 조사할수 없다
	//				 아래 코드는 항상 유효한 주소 반환
	//				 만일 대상체가 Dog 가 아니라면 반환된 p1을 
	//				 "p1->color = 10" 으로 사용하면 잘못된 메모리 참조
	Dog* p1 = static_cast<Dog*>(p);

	std::cout << p1 << '\n';


	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 대상체가 Dog 인지 확인후 캐스팅
	//				  Dog 가 아니라면 0 반환
	Dog* p2 = dynamic_cast<Dog*>(p);

	std::cout << p2 << '\n';


}











