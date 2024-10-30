#define USING_GUI
#include "cppmaster.h"

// 클라이언트 개발자는 "서버개발자"에게 2개의 파일을 받아야 합니다.

// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll : Proxy 가 담긴 동적 모듈( 클래스가 미리 컴파일 된것)

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. DLL 을 load 합니다.
	void* addr = ec_load_module("CalcProxy.dll");
				// linux : dlopen()   windows : LoadLibrary()

	// #2. DLL 에서 약속된 함수("create") 를 찾습니다.
	using FP = ICalc*(*)(); // 함수 포인터 타입
				// typedef ICalc*(*FP)()

	FP f = (FP)ec_get_function_address(addr, "create");
				// linux : dlsym()   windows : GetProcAddress()

	// #3. 약속된 함수를 호출해서 Proxy 를 생성해서 반환
	return f();  // DLL 내부에서 new Calc;
}

int main()
{
	ICalc* calc = load_proxy();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;

}





