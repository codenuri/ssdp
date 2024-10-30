#include "monitor.h"

// 모니터의 밝기를 변경하려면
// 1. 밝기를 변경하는 멤버 함수를 직접 호출
// 2. 모니터의 밝기를 변경하는 일을 하는 객체 사용 - command 패턴

class BrightCommand
{
	Monitor& m;
	int value;
	int old;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute()
	{
		old = m.get_brightness();
		m.set_brightness(value);
	}

	void undo()
	{
		m.set_brightness(old);
	}
};

int main()
{
	Monitor m;

	int old = m.get_brightness();
	m.set_brightness(90);		// 직접 변경
	
	// m의 밝기 상태를 이전 상태로 복구해 보세요
	m.set_brightness(old);


	BrightCommand cmd(m, 90);	
	cmd.execute();				// 객체 사용
	cmd.undo();
}