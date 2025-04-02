// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// client �����ڴ� 
// �� DLL �� �ִ� proxy class �̸���
// �˼�������, ����ص� �ȵ˴ϴ�. => ���� ������ ���ؼ�

// DLL ���ο� ��ӵ� �Լ��� ����� proxy ��ü�� �����մϴ�.
// => ���ο� proxy dll �� ���� �Ʒ� �Լ��� �ݵ�� �����Ǿ�� �մϴ�.

extern "C" __declspec(dllexport)  // dll ���� �Լ� ���鶧 �ʿ�
ICalc* create()
{
	return new Calc;
}

// ���ο� DLL �� ���͵� �̸� �Ѱ��� ����Ѵٸ�..
// �׳� proxy class �̸��� "Calc" �� ����ϸ� �ȵǳ��� ??
// => new Calc �Ϸ��� "Ŭ���� ���" �� �ʿ��ϰ�, Ŭ���̾�Ʈ ��ü�� �ٽ� ����
//    �ؾ� �մϴ�.

// �Լ� �̸��� "�̸�"���� �Լ��� ã���� �ֽ��ϴ�.!!
// => �ٽ� ���� �ʿ� �����ϴ�.
//----------------------------------------
// ���� �ϴ� ��
// linux �� c++ ������ : g++
// visual studio �� �����ϴ� c++ �����Ϸ� : cl.exe 

// ������ ���� ��ư - "developer ...." �Է�
// => developer command prompt for vs2022 ����
// => "calcproxy.cpp" �ҽ��� �ִ� ������ �̵���

// => cl calcproxy.cpp /LD     �� �����ϸ� "CalcProxy.dll" �����˴ϴ�.
//							   /LD �ɼ��� DLL �� �����϶�� �ɼ�
//								���� �����ϰ�, "calcproxy.dll" ������Ȯ��	
