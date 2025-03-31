// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	// #1. 모든 클래스는 되도록이면 생성자를 만들어서
	//     멤버를 초기화 하는 것이 좋습니다.
	Person(const std::string& n, int a) : name(n), age(a) {}
};
// 아래 주석대로 만들어 보세요
// 1. Person 에서 파생된 Student 만들어 보세요
// 2. 멤버 데이타 "int id" 추가하세요
// 3. Student 생성자 만들어 보세요
// 4. main 에서 Student 객체 생성해 보세요



int main()
{
	
//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	Person p1("kim", 20);
}


