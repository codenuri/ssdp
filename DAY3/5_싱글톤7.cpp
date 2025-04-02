#include <iostream>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	
	static Cursor& get_instance()
	{
//		Cursor instance;	// ���������� stack �� ����
							// stack �� ������� �Ѱ�
							// 2�� �����尡 ����Ǹ� ���� ���� ����
							// �����忡 ����

		// �Ʒ� �ڵ�� �����忡 �����մϴ�.
		// get_instance() �� ������ �����忡�� ���ÿ� ȣ��Ǿ
		// �Ʒ� �����ڴ� 1ȸ ȣ����� �����ϰ�
		// A �����尡 ������ ȣ��� B�� �����ϸ�
		// A �� ������ ȣ�����Ḧ ��� �մϴ�
		// => "spin lock" ���(busy waiting) �� ����ȭ
		// C#, java �� ����
		
		static Cursor instance; // static storage �� �Ҵ�
								// ��� �����尡 ����
								// ���� �Ѱ��� ������
	
		return instance;
	}


};
int main()
{
	Cursor& c1 = Cursor::get_instance();

}






