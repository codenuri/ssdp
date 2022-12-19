#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경(교체)할수있어야 한다.

// 방법 1. template method
// => 변하는 것을 가상함수로!!!
// => 변경하고 싶다면 파생 클래스를 만들어서 가상함수 재정의

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 숨은 변해야 하는 부분을 찾는다.!!
	// => 변해야 하는 부분을 가상함수로 분리한다.
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

			if (c == 13)
				break;

			if ( validate(c) ) // 변해야 하는 곳은 가상함수 호출로!
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};

// 이제 Validation 정책을 교체 하려면 Edit 파생 클래스를 설계해서
// validate 가상함수를 재정의하면 됩니다.
class NumEdit : public Edit
{
public:
	virtual bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;	
	NumEdit e;
//	AddressEdit e2;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}

// 변하는 것을 가상함수로!!
// => template method
// => Validation 정책을 Edit 가 포함하고 있다
//    다른 입력도구에서는 사용할수 없다.!
// => Validation 정책을 실행할때 변경할수없다
