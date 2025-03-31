#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : Validation 정책은 변경할수 있어야 한다.
// => Edit 는 라이브러리 내부 코드이다.
// => Edit 자체를 수정하지 않고도 Validation 정책을 변경할수 있어야 한다.

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분은 찾아서
	//    분리한다.
	// => 변하는 부분을 "가상함수" 로 분리

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
//			if (isdigit(c)) // 직접 validation!!
			if (validate(c)) // validation 정책을 담은 가상함수 호출
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};
// 위 디자인의 의도
// => Validation 을 변경하려면 Edit 파생 클래스를 만들어서
// => 약속된 가상함수를 override 하라는 것

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


