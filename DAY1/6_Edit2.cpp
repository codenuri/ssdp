#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경(교체)할수있어야 한다.

// 방법 1. 

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13)
				break;

			if (isdigit(c))
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};





int main()
{
	Edit e;	
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


