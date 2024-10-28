// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 - template method 패턴,  Edit2.cpp 소스
// #2. 변하는 것을 다른 클래스로 - strategy 패턴.      Edit3.cpp


// Validation 정책을 별도의 클래스로 설계
// => 교체 가능해야 하므로 "약한결합"
// => 인터페이스를 먼저 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

// 주민등록번호 : 931  1  확인

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

			if ( isdigit(c) ) 
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


