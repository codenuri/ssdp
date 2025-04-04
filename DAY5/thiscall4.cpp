#define USING_GUI
#include "cppmaster.h"

void foo(int id)
{
	std::cout << "foo\n";
}

// C 언어의 타이머 개념을 가지고 클래스를 만들어 봅시다.
class Clock
{
public:
};

int main()
{
	Clock c("AAA"); // AAA 는 이름

	c.Start(1000); // 1 초에 한번씩 자신의 이름을 출력해야 합니다.

	ec_process_message();
}