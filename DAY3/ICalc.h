#pragma once

// ICalc.h
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;

	virtual ~ICalc() {}
};

ICalc* load_proxy()
{
	// #1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
	// windows : LoadLibrary(),    linux : dlopen()

// #2. DLL 에서 약속된 함수 찾기
	using FP = ICalc * (*)();

	FP f = (FP)ec_get_function_address(addr, "create");
	// windows : GetProcAddress(),  linux : dlsym()

// #3. 약속된 함수로 Proxy 객체를 생성해서 반환
	return f();
}
