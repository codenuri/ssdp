#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// DLL 내부의 create() 호출
								// create() 안에서는 new Calc 수행
								// "delete" 해야 되지 않을까요 ?

	delete calc; // 이렇게 해도 될까요 ?
}


