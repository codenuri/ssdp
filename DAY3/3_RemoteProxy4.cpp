#define USING_GUI
#include "cppmaster.h"

// 클라이언트 개발자는 서버 개발자에게 2개의 파일을 받아야 합니다.

// ICalc.h       : Proxy 인터페이스가 있는 파일
// CalcProxy.dll : Proxy 가 있는 DLL 파일

#include "ICalc.h"


int main()
{
	ICalc* calc = new ? ; 


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}







