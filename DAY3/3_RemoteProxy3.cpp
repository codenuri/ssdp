#define USING_GUI
#include "cppmaster.h"


// 모든 Proxy 의 인터페이스

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
	// Calc 클래스(Proxy) 를 만든 사람     : Server 개발자
	// Calc 클래스(Proxy) 를 사용하는 사람  : Client 개발자

	// 아래 처럼 사용했다면 "강한 결합" 입니다.
	// 새로운 Proxy 가 나오면 아래 코드는 수정되어야 합니다.
	// Calc* calc = new Calc;

	// OCP 을 만족하기 위해 인터페이스 기반의 "약한결합" 으로 사용해야 합니다.

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}







