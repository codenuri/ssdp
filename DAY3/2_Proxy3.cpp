#define USING_GUI
#include "cppmaster.h"


// RPC : Remote Procedure Call. 다른 프로세스의 함수를 호출하는 것
//		 java 에서는 "RMI(Remote Method Invocation)"


// 서버와 대행자(Proxy)의 기능이 동일함을 보장하기 위해
// 인터페이스 도입

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;

	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pcalc = new Calc;

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





