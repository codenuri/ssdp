#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리 - 파생 클래스가 override 해서 교체
//    => template method 패턴의 모양

// 2. 변하는 것을 다른 클래스로!!

// validation 정책을 담은 클래스 설계
// => 교체 가능해야 하므로 interface 기반 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;

	virtual ~IValidator() {}
};

// 이제 모든 validator 는 IValidator 인터페이스를 구현해야 합니다.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int v) : value(v) {}

	bool validate(const std::string& s, char c)
	{
		return s.size() < value && isdigit(c);
	}
};

class Edit
{
	std::string data;

	IValidator* val = nullptr;

public:
	void set_validator(IValidator* p) { val = p; }


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) 
				break;

//			if (isdigit(c)) // 직접 validation
			if ( val == nullptr || val->validate(data, c)) // validation 을 외부객체에 위임
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


