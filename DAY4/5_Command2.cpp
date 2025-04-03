#include <iostream>
#include "monitor.h"

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