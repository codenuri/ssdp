#pragma once

// ICalc.h
// proxy 의 종류에 상관없이 참조계수 기능은 항상 필요 합니다.
// 별도의 인터페이스로 제공
struct IRefCount
{
	// 참조계수 기반으로 객체의 수명을 관리한다면
	// 참조계수 관련 함수는 반드시 인터페이스 에 있어야 합니다.
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};
struct ICalc : public IRefCount
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
	virtual ~ICalc() {}
};
// 다른 종류의 proxy 를 만들때도 아래 처럼
struct ILedServerProxy : public IRefCount
{
	// LED 관련 명령들.. 
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