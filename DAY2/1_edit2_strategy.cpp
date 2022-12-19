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



	std::string get_data()
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

	virtual bool iscomplete(const std::string& s) override
	{
		return s.size() == limit;
	}
};


int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidate(&v);	// edit 에 validation 정책 연결

	LimitDigitValidator v2(15);
	e.setValidate(&v2); // 실행하다 validation 정책교체
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


// 변하는 것을 다른 클래스로
// => strategy
// => validation 정책을 다른 입력도구도
//    사용가능.
// => validation 정책을 실행시간에 변경할수 있다

// Edit 의 Validation 정책 교체에는
// => Strategy 패턴(변하는 것을 다른 클래스로)이 좋다.

// 하지만, 도형편집기의 draw_imp() 의 경우는
// => 사각형을 그리는 방법은 "Rect" 만 사용하면 되고
//    실행시간에 교체도 필요 없다.
// => 멤버로 만들게 되므로 private 접근도 편리하다.
// => "template method(변하는것 가상함수로)가 좋다."