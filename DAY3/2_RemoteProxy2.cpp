#define USING_GUI
#include "cppmaster.h"

// client 를 아래 처럼 만들면

// #1. 1은 덧셈, 2는 뺄셈이라는 명령 코드를 항상 외우고 있어야 한다.
// => 명령코드는 많을수 있습니다.

// #2. 모든 클라이언트 제작자는 IPC 기술을 알아야 합니다.

// #3. 서버 장애 발생시, 모든 클라이언트에서 각각 장애 처리를 해야 합니다.


class Calc
{
	int server;
public:
	Cacl() { server = ec_find_server("Calc"); }

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


