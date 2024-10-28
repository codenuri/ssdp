// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); // 한글자씩 키보드에서 직접 읽기

			if (c == 13) break; // enter 키

			if (isdigit(c)) // 숫자일때만
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


