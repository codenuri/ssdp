// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// 객체를 안전하게 사용하게 하려면
	// 항상 생성자로.. 멤버 데이타를 초기화 하는 것이 좋습니다.
	People(const std::string& name, int age)
		: name(name), age(age)
	{
	}
};
int main()
{
//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? 
				// (초기화 되지 않은 객체)
				// error

	People p2("kim", 20); // ok.. 모든 사람은 만들때 
						// 초기화 되어야 한다.
}


