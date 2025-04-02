#define USING_GUI
#include "cppmaster.h"


// Proxy 는 교체 될수 있어야 합니다.
// => 인터페이스를 먼저 설계 합니다.

struct ICalc
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
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
	// proxy 제작자 : 서버제작자가 만들게 됩니다.
	// proxy 사용자 : client 제작자가 사용하게 됩니다.

	// 아래 처럼 사용하면 Proxy 클래스 이름을 직접 사용하므로
	// "강한 결합" 입니다.
	// => 교체 불가능합니다.
	// Calc* calc = new Calc;

	// 아래 처럼 약한 결합으로 사용해야 교체 가능합니다.
	// => 그런데 ? 생각해 보세요
	// => 해결책은 다음 소스..
	ICalc* calc = new ? ;


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


