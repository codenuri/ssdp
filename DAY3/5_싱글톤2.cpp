#include <iostream>

// ���� �Ѱ��� ��ü�� static ��� ����Ÿ�� ���� ��

// static �������� ����
// => get_instance() �� ó�� ȣ���Ҷ� Cursor ������ ȣ��
// => �ʿ��Ҷ� �ʱ�ȭ �ϰڴٴ� �ǵ�
// => lazy initialization

// static ��� ����Ÿ ����
// => ���α׷� ����� main �Լ� �������� Cursor ������ ȣ��
// => early initialization


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

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
	std::cout << "AAAA\n";
	Cursor& c1 = Cursor::get_instance();
}







