#include <iostream>
#include <string>
#include <conio.h>

// 변하는 코드를 분리하는 2가지 기술

// 1. 변하는 것을 가상함수로 !! => template method 패턴
// 2. 변하는 것을 다른 클래스로 => strategy 패턴.

// 모든 Validation 정책은 아래 인터페이스를 구현해야 한다.

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};
// 주민 등록 번호 : 931   1    확인



class Edit
{
	std::string data;

	IValidator* pval = nullptr; // 값의 유효성을 확인할때 사용할 객체
public:
	void setValidate(IValidator* p) { pval = p; }



	std::string getData()
	{
		data.clear();

		while (1)
		{

			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data)))
				break;

			if (pval == nullptr || pval->validate(data, c)) // 값의 유효성 확인을 다른객체에 위임
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};


// 이제 Edit 에서 사용할 다양한 "validation 정책을 담은"
// 클래스를 제공하면 됩니다.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidate(&v);	// edit 에 validation 정책 연결

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


