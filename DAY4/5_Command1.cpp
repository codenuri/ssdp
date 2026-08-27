#include <iostream>
#include "monitor.h"

class ResolutionCommand
{
	Monitor& m;
	int value;
public:
	ResolutionCommand(Monitor& m, int v) : m(m), value(v) {}
	
	void execute()
	{
		m.set_resolution(value);
	}
};


int main()
{
	Monitor m;

	// m 의 해상도를 1920으로 변경하고 싶다.
	// 방법 #1. 멤버 함수를 직접 호출 한다
	m.set_resolution(1920);

	// 방법 #2. command 패턴을 사용한다.
	// => 해상도를 변경하는 객체를 생성한후 실행
	ResolutionCommand rc(m, 1920); // m 을 1920 으로 변경하는 명령
	rc.execute();
}