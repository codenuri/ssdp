#include <iostream>
#include <string>
#include <conio.h>

// 변하지 않은 코드 내부의 변하는 것은 분리되어야 합니다

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 분리 - edit2.cpp (template method 의 전형적인형태)
// #2. 변하는 것을 다른 클래스로 분리 - 현재 소스
// => 교체 가능해야 한다.
// => 인터페이스 기반 설계

// validation 정책을 담은 클래스의 인터페이스(규칙)

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};
// 주민등록 번호 : 901    1      확인



class Edit
{
	std::string data;

	//------------------------------
	// Edit 가 사용할 Validation 정책
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* p) { val = p; }
	//-----------------------------------

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();  

			if (c == 13 && (val == nullptr || val->is_complete(data))   ) break;

			if (val == nullptr || val->validate(data, c)) // 값의 유효성 확인을 
			{							// 정책을 담은 객체에 위임
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 validation 정책을 가진 다양한 클래스를 만들면 됩니다.
// => 규칙 : IValidator 인터페이스 구현
class LimitDigitValidator : public IValidator
{
	int cnt;
public:
	LimitDigitValidator(int n) : cnt(n) {}

	bool validate(const std::string& s, char c) override
	{
		return s.size() < cnt && isdigit(c);
	}
	
	bool is_complete(const std::string& s) override
	{
		return s.size() == cnt;
	}
};

// 이메일 주소이 유효성을 확인하는 기능이 필요 하다
// edit2.cpp 라면
// => Edit 의 파생 클래스를 만들어서
// => validate() override 해서 이메일 주소 확인 기능 추가
// => template method 패턴의 전형적인 예제

// edit3.cpp 라면
// => Edit 와 관련없다
// => IValidator 의 규칙만 지키면 된다.
// => 즉, Validator 자체만 만들면 되고, 누가 사용(edit 또는 다른 입력 도구)하는지 몰라도 된다
// => "strategy" 라는 패턴을 사용한것



int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);  // edit 에게 validation 정책을 전달합니다

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


