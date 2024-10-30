// ICalc.h
#pragma once

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};



// Proxy Update 시 규칙
// 1. DLL 의 이름을 변경하면 안됩니다.("CalcProxy.dll 유지")
// 2. DLL 안에 "create" 가 있어야 합니다.

ICalc* load_proxy()
{
	// #1. DLL 을 load 합니다.
	void* addr = ec_load_module("CalcProxy.dll");
	// linux : dlopen()   windows : LoadLibrary()

// #2. DLL 에서 약속된 함수("create") 를 찾습니다.
	using FP = ICalc * (*)(); // 함수 포인터 타입
	// typedef ICalc*(*FP)()

	FP f = (FP)ec_get_function_address(addr, "create");
	// linux : dlsym()   windows : GetProcAddress()

// #3. 약속된 함수를 호출해서 Proxy 를 생성해서 반환
	return f();  // DLL 내부에서 new Calc;
}
