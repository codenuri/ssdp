// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>  // 멀티스레드 안전한 타입을 사용할때!!

class Calc : public ICalc
{
	int server;

//	int ref = 0;  // 멀티스레드환경에서 안전하게 +, - 되지 않음
	std::atomic<int> ref = 0;  // 멀티스레드 안전

public:

	void AddRef() { ++ref; }
	void Release() { if (--ref == 0) delete this; }

	~Calc() { std::cout << "~Calc\n"; }




	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

extern "C" __declspec(dllexport)  
ICalc* create()
{
	return new Calc;
}


// cl CalcProxy.cpp /LD