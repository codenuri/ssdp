#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경할수 있어야 합니다.

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에서 변해야 하는 곳이 있다면
	//    분리되어야 한다.
	// => 변하는 것을 별도의 가상함수로  분리한다.

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

			if ( validate(c) ) // 값의 유효성 확인(변하는것)을 가상함수에 의존
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 위 Edit 의 설계 의도는
// Validation 을 변경하고 싶다면 Edit 의 파생 클래스를 만들어서
// 약속된 가상함수를 override 하라는 것

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


