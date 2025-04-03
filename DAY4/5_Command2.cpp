#include <iostream>
#include "monitor.h"

// 어떤 작업을 직접하면
// => 해당하는 작업만 할수 있습니다.
// => 취소 하기 위한 데이타가 필요하면 외부에서 별도로 데이타를 관리해야 합니다.

// 어떤 작업을 수행하기 위해 클래스를 설계하면
// => 그 작업을 수행할수도 있고
// => 취소하는 방법도 만들수 있고
// => 취소에 필요한 데이타도 관리할수 있고
// => 해당 명령이 지금 선택 가능한지(N/W 끊어 진경우 데이타 전송 안됨)
//    도 관리가능합니다.

// command : 명령을 클래스로 설계.
// => undo 등을 가능하게 한다.


class ResolutionCommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	ResolutionCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		old_value = m.get_resolution();
		m.set_resolution(value); 
	}
	void undo()
	{
		m.set_resolution(old_value);
	}
};

int main()
{
	Monitor m;

	int old_value = m.get_resolution();
	m.set_resolution(1920);

	// 여기서 위 명령을 취소(실행되기 이전상태로) 해보세요
	m.set_resolution(old_value);


	ResolutionCommand cmd(m, 1920);
	cmd.execute();
	cmd.undo();
}