#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age)
		: name(name), age(age)
	{
	}
};
// 1. People 에서 파생된 Student 만들어 보세요
// 2. 학번(int id) 를 멤버 데이타로 추가하세요
// 3. 생성자 만드세요

class Student : public People
{
	int id;
public:
	// 생성자를 아래처럼 만들면 안됩니다.
	// 사용자 코드				// 컴파일러가 변경한 코드
//	Student(int id) : id(id) {} // Student(int id) : People(), id(id) {} 

	// 기반 클래스인 People 에 디폴트 생성자가 없으므로
	// 반드시 "이름과 나이를 전달"해야합니다.
	Student(const std::string& name, int age, int id)
		: People(name, age), id(id) {}
};

int main()
{
	// Student 객체 생성해 보세요
	Student s("kim", 20, 99);
}







