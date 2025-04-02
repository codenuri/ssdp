#include <iostream>

// ���� �Ѱ��� ��ü�� static ��� ����Ÿ�� ���� ��

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance; // error. �ڽ��� Ÿ���� ��ü�� ����� ������ ����.
	static Cursor instance; // ok. static �� ����.

public:
	static Cursor& get_instance()
	{
//		static Cursor instance;
		return instance;
	}
};
Cursor Cursor::instance;


int main()
{
	Cursor& c1 = Cursor::get_instance();
}







