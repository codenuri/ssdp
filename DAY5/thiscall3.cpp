#define USING_GUI
#include "cppmaster.h"

void foo(int id)
{
	std::cout << "foo\n";
}

int main()
{
	int id = ec_set_timer(1000, // �ð�(ms����)
				          &foo); // ȣ��� �Լ� 

	ec_process_message();
}