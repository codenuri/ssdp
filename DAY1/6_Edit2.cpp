// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 핵심 #1. validation 정책은 사용자가 변경할수 있어야 한다.

// 핵심 #2. 변하는 것을 가상함수로...


class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 흐름 내부의 변하는 것을 찾아라
	// => 변하는 것을 가상함수로 분리

	virtual bool validate(char c)
	{
		return true;
	}


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break; 

			if ( validate(c) ) // 값의 유효성 확인은 가상함수를 통해서!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Edit 사용자는
// Validation 정책을 변경하려면 "Edit" 파생클래스를 만들고
// 약속된 가상함수를 override 하면됩니다.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


