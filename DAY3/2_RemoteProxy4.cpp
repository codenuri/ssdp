#define USING_GUI
#include "cppmaster.h"

// client 제작자는 서버 제작자로 부터 2개의 파일을 받아야 합니다.
// 
// ICalc.h       : 인터페이스가 담긴 헤더
// CalcProxy.dll : proxy class 가 있는 동적 모듈

#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);


	std::cout << n1 << ", " << n2 << std::endl;

}


