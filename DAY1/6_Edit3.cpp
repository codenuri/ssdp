// 33 page ~ 
#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 - template method 패턴,  Edit2.cpp 소스
// #2. 변하는 것을 다른 클래스로 - strategy 패턴.      Edit3.cpp


// Validation 정책을 별도의 클래스로 설계
// => 교체 가능해야 하므로 "약한결합"
// => 인터페이스를 먼저 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민등록번호 : 931  1  확인




class Edit
{
	std::string data;

	IValidator* val = nullptr;		// 값의 유효성확인에 사용할객체
public:
	void set_validator(IValidator* v) { val = v; }


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (val == nullptr || val->is_complete(data))   ) break;

			if ( val == nullptr || val->validate(data, c) ) // 유효성여부를 다른 객체에 위임
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Edit 에서 사용할 다양한 "Validator 객체(유효성 확인 전략을 담은 클래스)"
// 를 만들면 됩니다.
class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == limit;
	}
};
/*
class email_validator : public IValidator {};
class pinnumber_validator : public IValidator {};
class phonenumber_validator : public IValidator {};
*/

int main()
{
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v); // 핵심 

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


