#define USING_GUI
#include "cppmaster.h"

// Proxy 패턴 : 기존 요소의 대행자를 만드는 패턴
// remote proxy : 원격지 서버에 대한 대행자

// 장점 
// 1. "1", "2" 가 아닌 "Add", "Sub" 를 사용할수 있다.
// 2. 자주 사용하는 연산에 대한 캐쉬 제공 가능
// 3. Client 의 변화 없이 서버에 대한 update 가능.


// Proxy : 함수 호출(Add) 를 명령코드(1)로 변경해서 서버에 전달
// 
// Stub  : 도착한 명령코드(1) 를 다시 함수호출(Server.Add) 로 변경

// 흔히 "proxy-stub" 통신 이라고 합니다. 
// server에 있는 "handler" 함수가 stub 입니다.



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





