#define USING_GUI
#include "cppmaster.h"

// 클라이언트 개발자는 서버 개발자에게 2개의 파일을 받아야 합니다.

// ICalc.h       : Proxy 인터페이스가 있는 파일
// CalcProxy.dll : Proxy 가 있는 DLL 파일

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
				// windows : LoadLibrary(),    linux : dlopen()

	// #2. DLL 에서 약속된 함수 찾기
	using FP = ICalc* (*)();

	FP f = (FP)ec_get_function_address(addr, "create");
				// windows : GetProcAddress(),  linux : dlsym()

	// #3. 약속된 함수로 Proxy 객체를 생성해서 반환
	return f();
}

int main()
{
	ICalc* calc = load_proxy(); 


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}







