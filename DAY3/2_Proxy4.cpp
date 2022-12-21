#define USING_GUI
#include "cppmaster.h"


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

// 서버의 대행자(Proxy) 는 누가 만들게 될까요 ?

// 1. Server 제작자 <== 정답
// 2. Client 제작자


int main()
{
	// 아래 처럼 만들면 "클라이언트가 Proxy"를 
	// 강한 결합으로 사용하게 됩니다.
	// "새로운 Proxy" 가 배포 되면
	// 클라이언트 코드가 수정되게 됩니다.
	// Calc* pcalc = new Calc;

	// 클라이언트는 Proxy 사용시 약한 결합으로 사용해야 합니다.

	ICalc* pcalc = new ? ? ? ; // 문제
								// => "Calc" 라는 클래스 이름없이
								//    객체 생성이 필요.!
								// => Proxy 를 동적모듈(.dll, .so) 로 배포해야 한다



	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





