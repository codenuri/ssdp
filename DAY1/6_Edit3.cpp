#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и� - �Ļ� Ŭ������ override �ؼ� ��ü
//    => template method ������ ���

// 2. ���ϴ� ���� �ٸ� Ŭ������!!

// validation ��å�� ���� Ŭ���� ����

class LimitDigitValidator
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
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) 
				break;

			if (isdigit(c))
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


