#include <iostream>
#include <string>
#include <conio.h>


// Edit 에 입력 값의 유효성을 확인하는 "Validation" 기능을 넣어 봅시다.

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

			if (c == 13) // enter 키
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
	Edit e;	// 이순간 화면에 edit 컨트롤이 나타난다고 가정..
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


