#include <iostream>
#include <string>
#include <conio.h>

// 핵심. Validation 정책은 변경할수 있어야 한다.

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 "변하는 부분" 은 분리되어야 한다
	// => 변하는 코드를 별도의 가상함수로 분리한다
	// => "template method" 패턴의 전형적인 형태 입니다.

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

			if (validate(c)) // 변해야 하는 정책은 "별도의 가상함수" 사용
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 위 설계의 의도
// Edit 의 Validation 정책을 변경하려면
// 1. Edit 의 파생 클래스를 만든다
// 2. 약속된 가상함수인 "validate" 를 override 해서 validation 정책 제공

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

/*
class AddressEdit : public Edit
{
public:
	bool validate(char c) override
	{
		// 주소 입력을 위한 validation 정책
	}
};
*/

int main()
{
//	Edit e;
	NumEdit e;
	AddressEdit e2;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}




// github.com/codenuri/ssdp 에서 DAY2.zip 받으시면 됩니다