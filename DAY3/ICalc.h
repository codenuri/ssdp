#pragma once

// ICalc.h
struct ICalc
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
	virtual ~ICalc() {}
};



ICalc* load_proxy()
{
	// #1. dll load
	void* addr = ec_load_module("CalcProxy.dll");
	// windows : LoadLibrary()
	// linux   : dlopen()

// #2. 약속된 함수 찾기
	typedef ICalc* (*F)(); // 함수 포인터 타입

	F f = (F)ec_get_function_address(addr, "create");
	// windows : GetProcAddress()
	// linux   : dlsym()

//	printf("%p, %p\n", addr, f);

	// #3. 약속된 함수를 호출해서 proxy 생성후 반환
	return f(); // DLL 내부의 create() 호출
}