#include <iostream>
#include "monitor.h"

class ResolutionCommand
{
	Monitor& m;
	int value;
public:
	ResolutionCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() { m.set_resolution(value);}
};

int main()
{
	Monitor m;

	// m 의 해상도를 1920으로 변경하고 싶다.

	// 방법 #1. 멤버 함수를 직접 호출
	m.set_resolution(1920);


	// 방법 #2. Command 패턴을 사용
	ResolutionCommand cmd(n, 1920);
	cmd.execute();
}