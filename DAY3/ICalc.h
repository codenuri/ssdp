// ICalc.h
#pragma once

// Proxy 객체의 수명을 참조 계수(reference counting) 으로
// 관리한다면
// 참조 계수 함수들은 인터페이스에 있어야 합니다.

// 다양한 서버를 만들고, 해당 서버의 Proxy 를 만든다고 할때
// Proxy 에 따라, Add, Sub 이름을 달라지지만
// 참조계수 함수는 동일합니다.
// 참조계수 함수는 별도의 인터페이스로!!

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

/*
struct IMotorServerProxy : public IRefCount
{
	// 모터서버용 Proxy 함수
};
*/



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
