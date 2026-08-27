#include <iostream>
#include "monitor.h"

// command 패턴을 사용하기로 했다면
// 프로그램에서 사용하는 모든 명령에 해당하는 작업을 클래스로 설계해야 합니다.

// 명령의 인터페이스를 먼저 설계합니다.
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

// 모든 명령은 ICommand 를 구현하기로 약속
class ResolutionCommand : public ICommand
{
	Monitor& m;
	int old_value;
	int value;
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

	ResolutionCommand rc(m, 1920);
	rc.execute();
	rc.undo();
}