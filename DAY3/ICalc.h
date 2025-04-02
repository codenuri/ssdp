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

// #2. ��ӵ� �Լ� ã��
	typedef ICalc* (*F)(); // �Լ� ������ Ÿ��

	F f = (F)ec_get_function_address(addr, "create");
	// windows : GetProcAddress()
	// linux   : dlsym()

//	printf("%p, %p\n", addr, f);

	// #3. ��ӵ� �Լ��� ȣ���ؼ� proxy ������ ��ȯ
	return f(); // DLL ������ create() ȣ��
}