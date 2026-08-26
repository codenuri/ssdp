#pragma once

// 서버가 여러종류이고, 각각의 Proxy 가 있을때
// 모두 Reference Counting 기술을 사용하면
// 결국 AddRef(), Release() 는 모두 필요 합니다.

struct IRefCount
{
	// 참조계수로 객체의 수명을 관리하는 경우
	// => 참조계수용 함수도 반드시 인터페이스에 있어야 합니다
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

// ICalc.h
struct ICalc : public IRefCount 
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
