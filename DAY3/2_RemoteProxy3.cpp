#define USING_GUI
#include "cppmaster.h"

// Proxy 제작자 : 서버제작자
// Proxy 사용자 : 클라이언트제작자

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
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

int main()
{
	// 아래  처럼 사용하면 "강한결합" 이 됩니다.
	// 새로운 Proxy 가 배포되면 아래 코드는 수정되어야 합니다.
	// Calc* calc = new Calc;

	// 약한결합(인터페이스)로 사용해야 합니다.
	ICalc* calc = new ? ; // ? 를 어떻게 해야 할까요 ?
						  // Proxy 는 소스로 배포하면 안됩니다.
						  // 동적 모듈(dll, so) 로 배포 되어야 합니다.
						  // => 다음 단계에서 해결


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;

}





