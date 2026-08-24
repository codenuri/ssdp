#include <iostream>
class Animal
{
public:
	int age;

	virtual ~Animal() {} // 가상 소멸자 문법 - 오늘 오후에 배우게 됩니다.
						 // 이제 Animal 에 가상함수가 있으므로
						 // Dog 도 물려 받게 되고
						 // => 가상함수 테이블이 생기고 "타입 정보 관리됩니다"
						 // => dynamic_cast 사용가능

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
	// 단, 사용하려면 "메모리에 타입정보"가 있어야 한다
	// => C++ 은 가상함수를 가진 클래스만 타입정보를 유지 한다
	// => 가상 함수 테이블 이라는 곳에 타입 정보 관리
	// => 가상 함수가 없는 타입은 dynamic_cast 사용 못함!!
	// => 모든 타입의 객체가 "타입 정보"를 가지는 것은 오버헤드!!!
	// => 필요한 경우만 관리하겠다는 것.. 
	// => 대부분 가상함수가 있는 타입에 대해서만 타입 정보 필요
	Dog* p2 = dynamic_cast<Dog*>(p);

	std::cout << p2 << '\n';


}











