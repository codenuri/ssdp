#define USING_GUI
#include "cppmaster.h"

// 클라이언트 개발자는 "서버개발자"에게 2개의 파일을 받아야 합니다.

// ICalc.h       : 인터페이스가 있는 헤더
// CalcProxy.dll : Proxy 가 담긴 동적 모듈( 클래스가 미리 컴파일 된것)

#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;

}





