#include "monitor.h"

// 모니터의 밝기를 변경하려면
// 1. 밝기를 변경하는 멤버 함수를 직접 호출
// 2. 모니터의 밝기를 변경하는 일을 하는 객체 사용 - command 패턴


// 어떤 일을 하는 함수(멤버함수)를 직접호출하면
// => "해당하는 일"만 수행한다.

// command 패턴 : 해당하는 일을 수행하는 객체를 만들면
// => "해당하는 일"도 수행하고
// => "취소를 위한 데이타 보관도 가능하고"
// => "취소 하는 코드를 제공할수 도 있고"
// => 현재 상태에서 취소가 가능한지 조사도 가능
//    네트워크 전송된 데이타는 취소 안됨

// 명령은 여러개가 필요 합니다.
// 인터페이스를 먼저 제공
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

class BrightCommand : public ICommand
{
	Monitor& m;
	int value;
	int old = 0;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute()
	{
		old = m.get_brightness();
		m.set_brightness(value);
	}

	bool can_undo() { return true;  }

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