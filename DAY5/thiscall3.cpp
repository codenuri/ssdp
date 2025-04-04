#define USING_GUI
#include "cppmaster.h"

void foo(int id)
{
	std::cout << "foo\n";
}

int main()
{
	int id = ec_set_timer(1000, // 시간(ms단위)
				          &foo); // 호출된 함수 

	ec_process_message();
}