#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// DLL 안에서 "new Calc" 하게 됩니다.
								// 사용후 delete 해야 되지 않을까요 ?

	int n1 = calc->Add(1, 2);


	delete calc;	// 이렇게 해도 될까요 ?
					// DLL 을 만들때 사용한 컴파일러와
					// 클라이언트를 만들때 사용한 컴파일러가 다를수 있습니다
					// (동일 컴파일러도 버전이 다를수 있습니다.)
					// DLL에서 new 한것을 exe 에서 delete 하는 것은
					// 안전하지 않습니다.
					// DLL에서 new 한것은 DLL 이 delete 해야 합니다.
}





