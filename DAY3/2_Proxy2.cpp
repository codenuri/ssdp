#define USING_GUI
#include "cppmaster.h"

// 서버를 "대신" 하는 클래스를 설계 합니다. 

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc");  }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pcalc = new Calc;

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





