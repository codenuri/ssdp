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
	ICalc* pcalc = ReloadProxy(); 

	pcalc->AddRef(); // 규칙 1. Proxy 포인터를 얻으면 참조계수 증가

	ICalc* p2 = pcalc;
	p2->AddRef();	 // 규칙 2. Proxy 포인터 복사하면 참조계수 증가

	int n = pcalc->Add(1, 2);


	// 규칙 3. 각 포인터를 사용후에는 참조계수 감소
	p2->Release();

	std::cout << "========" << std::endl;
	pcalc->Release();

}





