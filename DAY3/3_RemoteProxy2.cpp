#define USING_GUI
#include "cppmaster.h"

// remoteproxy1.cpp 와 같이
// => C 스타일의 IPC 관련 함수를 직접 사용하면

// 단점
// #1. 모든 Client 개발자가 IPC 기술을 알아야 한다.
// => 서버는 한개 지만 Client 는 여러개 일수 있다

// #2. 서버 장애시 "모든 클라이언트에서 각각 처리 해야 한다"

// #3. 덧셈은 1, 뺄셈은 2 와 같은 명령코드를 모두 알아야 한다
// => 실제 명령 코드는 많을수 있다

//-------------------------------------------
// Proxy 패턴을 사용해 봅시다.
// => 서버를 대신하는 클래스를 제공합니다.
// => "Remote Proxy" 라고 불리는 기술

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	// 1, 2 라는 명령 코드를 "Add, Sub" 의 함수 호출로 변경해 준것
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





