#define USING_GUI
#include "cppmaster.h"

// client �����ڴ� ���� �����ڷ� ���� 2���� ������ �޾ƾ� �մϴ�.
// 
// ICalc.h       : �������̽��� ��� ���
// CalcProxy.dll : proxy class �� �ִ� ���� ���

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. dll load
	void* addr = ec_load_module("CalcProxy.dll");
				// windows : LoadLibrary()
				// linux   : dlopen()

	// #2. ��ӵ� �Լ� ã��
	typedef ICalc*(*F)(); // �Լ� ������ Ÿ��

	F f = (F)ec_get_function_address(addr, "create");
				// windows : GetProcAddress()
				// linux   : dlsym()

//	printf("%p, %p\n", addr, f);

	// #3. ��ӵ� �Լ��� ȣ���ؼ� proxy ������ ��ȯ
	return f(); // DLL ������ create() ȣ��
}

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


