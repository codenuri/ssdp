// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// 왜 Upcasting 이 중요한가 ?

	// 장점(활용) #1. 
	std::vector<Dog*>    v1;	// Dog 객체만 보관 가능한 컨테이너
	std::vector<Animal*> v2;	// 모든 동물 객체를 보관 가능한 컨테이너
								// 동종(동일 기반 클래스를 사용하는 타입)
								// 을 보관하는 컨테이너
}
