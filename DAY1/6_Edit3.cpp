#include <iostream>
#include <string>
#include <conio.h>

// 변하지 않은 코드 내부의 변하는 것은 분리되어야 합니다

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 분리 - edit2.cpp (template method 의 전형적인형태)
// #2. 변하는 것을 다른 클래스로 분리 - 현재 소스
// => 교체 가능해야 한다.
// => 인터페이스 기반 설계

// validation 정책을 담은 클래스의 인터페이스(규칙)

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};
// 주민등록 번호 : 901    1      확인



class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();  

			if (c == 13) break; 

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


