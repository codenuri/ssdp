#define USING_GUI
#include "cppmaster.h"

// Proxy5.cpp

// 클라이언트 제작자는 서버 제작자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 담긴 헤더
// CalcProxy.dll : Proxy 구현이 담긴 동적 모듈

#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
						// => linux : dlopen()
						// => window: LoadLibrary()
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");
						// => linux : dlsym()
						// => Window: GetProcAddress()
	printf("Create함수주소 : %p\n", f); 
	return f(); // 결국 "Create()"  호출
}

int main()
{
	ICalc* pcalc = ReloadProxy();

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





