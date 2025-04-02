#pragma once

// ICalc.h
// proxy �� ������ ������� ������� ����� �׻� �ʿ� �մϴ�.
// ������ �������̽��� ����
struct IRefCount
{
	// ������� ������� ��ü�� ������ �����Ѵٸ�
	// ������� ���� �Լ��� �ݵ�� �������̽� �� �־�� �մϴ�.
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
// �ٸ� ������ proxy �� ���鶧�� �Ʒ� ó��
struct ILedServerProxy : public IRefCount
{
	// LED ���� ��ɵ�.. 
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