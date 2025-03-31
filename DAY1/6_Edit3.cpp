#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리 - 파생 클래스가 override 해서 교체
//    => template method 패턴의 모양

// 2. 변하는 것을 다른 클래스로!!


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

			if (c == 13) // enter
				break;

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
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


