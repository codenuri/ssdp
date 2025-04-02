#define USING_GUI
#include "cppmaster.h"

// 아래 Calc 는 결국 서버를 대신 합니다. 서버의 대행자(remote proxy)

// #1. client 제작자는 1, 2 대신 Add, Sub 를 사용하게 됩니다.

// #2. 모든 클라이언트 제작자는 IPC 기술을 몰라도 됩니다.

// #3. 서버 장애 발생시, proxy 내부에서 장애처리를 하면 됩니다.

// #4. 자주 요청되는 결과는 캐쉬에 보관했다가 반환할수도 있습니다. 






class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


