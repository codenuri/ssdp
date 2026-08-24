// 1_생성자3.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};

//Person p; // 이렇게 객체를 생성할수 있으면 좋을까요 ?
		  // 이름과 나이가 초기화 되지 않은 객체가 탄생하면 좋은 코드 일까요 ?
		  // => 나쁜 코드.. 
		  // => 모든 객체를 적절히 초기화된 상태로 만들어 져야 합니다.
		  // => 즉, 반드시 생성자를 제공해서 초기화해야 합니다.


// 1. 생성자를 추가해서 id 초기화 하세요
// 2. main 에서 Student 객체를 생성해 보세요
class Student : public Person
{
	int id;
public:
//	Student(int id) : id(id) {}		// error
//	Student(int id) : Person(), id(id) {}  // 컴파일러가 변경한 코드

	// 핵심
	// Student 설계자는 Person 의 디폴트 생성자가 없다는 것을 알고 있어야 합니다.
	// 그래서 Student 생성자에서 Person 생성자를 명시적으로 호출해야 합니다
	
	// 이 내용은 C++, C#, Java 등 대부분의 객체지향 언어에서 동일한 내용입니다.
	// => 반드시 아래 코드를 정확히 이해해 두세요
	// => Person 의 생성자를 다시 호출하는 것이 핵심
	Student(const std::string& name, int age, int id) : Person(name, age), id(id) {}
};

int main()
{
	Student s("kim", 20, 99);

}


