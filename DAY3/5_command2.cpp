#include "monitor.h"

// 모니터의 밝기를 변경하려면
// 1. 밝기를 변경하는 멤버 함수를 직접 호출
// 2. 모니터의 밝기를 변경하는 일을 하는 객체 사용 - command 패턴


int main()
{
	Monitor m;
	m.info();

	m.set_brightness(90);
	m.info();
}