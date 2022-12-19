// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// Upcasting 활용 #1
	std::vector<Dog*>    v1; // Dog 객체만 보관하는 컨테이너!!
	std::vector<Animal*> v2; // 동종(동일 기반 클래스를 사용하는 타입)을 저장가능
						     // Animal 로 부터 파생된 모든 클래스의 객체를
							// 저장가능

}