#include <iostream>
#include <string>
#include <conio.h>

// �ٽ� : Validation ��å�� �����Ҽ� �־�� �Ѵ�.
// => Edit �� ���̺귯�� ���� �ڵ��̴�.
// => Edit ��ü�� �������� �ʰ� Validation ��å�� �����Ҽ� �־�� �Ѵ�.

class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� ã�Ƽ�
	//    �и��Ѵ�.
	// => ���ϴ� �κ��� "�����Լ�" �� �и�

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

			if (validate(c)) // validation ��å�� ���� �����Լ� ȣ��
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


