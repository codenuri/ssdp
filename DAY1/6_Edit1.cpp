#include <iostream>
#include <string>
#include <conio.h>

// 33page ~

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
				return;

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; // 개행
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


