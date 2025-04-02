#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// DLL 내부의 create() 호출
								// create() 안에서는 new Calc 수행
								// "delete" 해야 되지 않을까요 ?

	delete calc; // 이렇게 해도 될까요 ?
				 // dll 을 만들때 사용한 컴파일러와
				 // exe 를 만들때 사용한 컴파일러가 다를수 도 있습니다.

	// 모듈안에서 할당한 자원은
	// 동일 모듈에서 해지하는 것이 원칙 입니다.

}


