#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и� - �Ļ� Ŭ������ override �ؼ� ��ü
//    => template method ������ ���

// 2. ���ϴ� ���� �ٸ� Ŭ������!!

// validation ��å�� ���� Ŭ���� ����
// => ��ü �����ؾ� �ϹǷ� interface ��� ����

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;

	virtual ~IValidator() {}
};

// ���� ��� validator �� IValidator �������̽��� �����ؾ� �մϴ�.
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

//			if (isdigit(c)) // ���� validation
			if ( val == nullptr || val->validate(data, c)) // validation �� �ܺΰ�ü�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};

// ���ڸ�(���ھȵ�) 10�� ������ �Է¹޴� validator ����� ������
class TenCharacterValidator : public IValidator
{

};


int main()
{
	Edit e;

//	LimitDigitValidator v1(5);
//	e.set_validator(&v1);	// e ���� validation �� �ʿ� �ϸ�
							// v1 �� ����϶�� ����!!

	TenCharacterValidator v2;
	e.set_validator(&v2);

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


