#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();	// DLL 안에서 "new Calc" 하게 됩니다.
								// 사용후 delete 해야 되지 않을까요 ?

	int n1 = calc->Add(1, 2);


	delete calc;	// 이렇게 해도 될까요 ?
}





