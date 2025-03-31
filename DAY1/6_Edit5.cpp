#include <iostream>
#include <string>
#include <conio.h>


struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;

	// �Է��� �Ϸ�Ǿ��°� ?
	// �ֹ� ��ȣ�� ���� validator ��� 13�ڸ��� �Է� �Ǿ�� �Ѵ�.
	virtual bool is_complete(const std::string& s) { return true; }


	virtual ~IValidator() {}
};



class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int v) : value(v) {}

	bool validate(const std::string& s, char c)
	{
		return s.size() < value && isdigit(c);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == value;
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

			if (c == 13 && (val == nullptr || val->is_complete(data)) )
				break;

			if (val == nullptr || val->validate(data, c)) 
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

	LimitDigitValidator v1(5);
	e.set_validator(&v1);	


	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


