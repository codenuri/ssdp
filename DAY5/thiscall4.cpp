#define USING_GUI
#include "cppmaster.h"

void foo(int id)
{
	std::cout << "foo\n";
}

// C ����� Ÿ�̸� ������ ������ Ŭ������ ����� ���ô�.
class Clock
{
public:
};

int main()
{
	Clock c("AAA"); // AAA �� �̸�

	c.Start(1000); // 1 �ʿ� �ѹ��� �ڽ��� �̸��� ����ؾ� �մϴ�.

	ec_process_message();
}