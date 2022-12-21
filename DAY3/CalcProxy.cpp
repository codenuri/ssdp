#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>

class Calc : public ICalc
{
	int server;
//	int refcount = 0;
	std::atomic<int> refcount = 0;
public:
	~Calc() { std::cout << "~Calc" << std::endl; }

	void AddRef() { ++refcount; }
	
	void Release()
	{ 
		if (--refcount == 0) 
			delete this; 
	}



	Calc() { server = ec_find_server("Calc"); }




	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};





extern "C" __declspec(dllexport)
ICalc* Create()
{
	return new Calc;
}


