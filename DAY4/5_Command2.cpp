#include <iostream>
#include "monitor.h"

// 해야할 일을 있을때 

// 그일을 직접 하면(m.set_resoultion())
// => 취소 등의 작업을 하기위해 외부에 데이터를 보관하고 있어야 합니다.
// => 취소 작업도 다른 함수로 구현해야 합니다.

// command 패턴을 사용하면
// => 해당 작업을 수행하고
// => 취소 하기 위한 데이타도 보관할수 있고
// => 취소 하기 위한 동작도 같이 정의 할수 있습니다.
// => 즉, 명령하나를 위한 모든 작업을 한개의 타입을 설계할수 있습니다.



class ResolutionCommand
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

	int old = m.get_resolution();
	m.set_resolution(1920);

	// 방금한 작업을 취소 하고 싶다
	// => 즉, m 을 이전 상태로 되돌리고 싶다
	// => 이전상태의 모든 값을 꺼내서, 외부 어딘가에 보관해야 한다.
	// => "해상도 뿐 아니라 다른 상태도 많다면" 항상 그 데이타를 외부에서 계속 관리해야한다
	m.set_resolution(old);



	ResolutionCommand rc(m, 1920); 
	rc.execute();
	rc.undo();
}