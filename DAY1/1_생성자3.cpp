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

class Student : public Person
{
	int id;
public:
	// 아래처럼 만들면 에러 입니다.(컴파일러가 변경한 코드 참고)
	// 사용자 코드				// 컴파일러가 변경
//	Student(int id) : id(id) {}	// Student(int id) : Person(), id(id) {}

	// Student 개발자는 Person 에 디폴트 생성자가 없다는 것을
	// 알고 있어야 합니다.
	// 그래서, Student 생성자에서 Person 생성자를 명시적 호출해야 합니다.
	Student(const std::string& name, int age,  int id) 
		: Person(name, age ), id(id) {}
};

int main()
{
	Student s("kim", 20, 11);

//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	
	Person p1("kim", 20); // ok. 좋은 코드. 초기화된 객체
}


