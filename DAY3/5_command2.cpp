#include "monitor.h"

// 모니터의 밝기를 변경하려면
// 1. 밝기를 변경하는 멤버 함수를 직접 호출
// 2. 모니터의 밝기를 변경하는 일을 하는 객체 사용 - command 패턴

class BrightCommand
{
	Monitor& m;
	int value;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute()
	{
		m.set_brightness(value);
	}
};

int main()
{
	Monitor m;
	m.set_brightness(90);
	
	BrightCommand cmd(m, 90);
	cmd.execute();
}