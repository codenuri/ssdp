#define USING_GUI
#include "cppmaster.h"

// client 제작자는 서버 제작자로 부터 2개의 파일을 받아야 합니다.
// 
// ICalc.h       : 인터페이스가 담긴 헤더
// CalcProxy.dll : proxy class 가 있는 동적 모듈

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. dll load
	void* addr = ec_load_module("CalcProxy.dll");
				// windows : LoadLibrary()
				// linux   : dlopen()

	// #2. 약속된 함수 찾기
	typedef ICalc*(*F)(); // 함수 포인터 타입

	F f = (F)ec_get_function_address(addr, "create");
				// windows : GetProcAddress()
				// linux   : dlsym()

//	printf("%p, %p\n", addr, f);

	// #3. 약속된 함수를 호출해서 proxy 생성후 반환
	return f(); // DLL 내부의 create() 호출
}

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


