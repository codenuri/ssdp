#define USING_GUI
#include "cppmaster.h"

// remoteproxy1.cpp 처럼 만들면
// 1. 모든 클라이언트 제작자가 IPC 기술이 필요

// 2. 서버의 장애 처리를 모든 클라이언트가 직접해야 합니다.

// 3. 덧셈은 1, 뺄셈은 2 같은 명령코드를 외우고 있어야 합니다.

// 서버를 대신하는 대행자(proxy)를 만들어서 사용합니다.

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	void Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	void Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

int main()
{
	// 이제 클라이언트제작자는 서버를 대신하는 클래스인 "Calc" 사용합니다.
	Calc* calc = new Calc;

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;

}





