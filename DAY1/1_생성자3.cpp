// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};

// 1. Person 에서 파생된 Student 클래스 만들어 보세요
// 2. "int id" 멤버 추가해 보세요
// 3. Student 생성자 만들어서 id 초기화해 보세요
// 4. main 에서 Student 객체 생성해 보세요


int main()
{
//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	
	Person p1("kim", 20); // ok. 좋은 코드. 초기화된 객체
}


