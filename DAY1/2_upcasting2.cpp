// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 #1. 동종을 보관하는 컨테이너
	std::vector<Dog*>    v1;	// Dog 객체만 보관 가능한 vector
	std::vector<Animal*> v2;	// 모든 동물(Animal 파생 클래스)
								// 를 보관하는 vector

}
