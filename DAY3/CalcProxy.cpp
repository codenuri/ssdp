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

// Client 개발자는 Proxy 클래스의 이름을 
// 알수 없고, 알 필요도 없고, 사용해도 안됩니다.
// DLL 내부에 약속된 함수를 제공하고 해당 함수에서 Calc 객체 생성
extern "C" __declspec(dllexport)	// windows DLL 에서 함수 만들때 필요한것
ICalc* create()						// 리눅스 .so 에서는 필요 없음
{
	return new Calc;
}

// Cient 개발자는
// 1. DLL Load
// 2. DLL 안에 있는 약속된 함수("create") 호출하면 Proxy 생성!





