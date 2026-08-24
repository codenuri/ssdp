#include <iostream>
#include <string>
#include <conio.h>

// 사용자에게 입력 받는 Edit 라는 Control(Widget)을 만들어 봅시다
class Edit
{
	std::string data;
public:
	// 숫자만 입력되는 edit 만들기
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();  // 1자 입력

			if (c == 13) break; // enter 입력

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


