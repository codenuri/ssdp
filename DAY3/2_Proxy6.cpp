#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	printf("Create함수주소 : %p\n", f);
	return f(); 
}

int main()
{
	ICalc* pcalc = ReloadProxy(); // 결국 DLL 내부에서 "new Calc" 합니다.

	int n = pcalc->Add(1, 2);


	delete pcalc; // 이렇게 해도 될까요 ?? 안전한가요 ??
				// => 안전하지 않습니다..
				// 
				// DLL 내부에서 할당한 메모리는
				// DLL 내부에서 delete 하는 것이 가장 안전합니다.

}





