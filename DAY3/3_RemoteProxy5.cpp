#define USING_GUI
#include "cppmaster.h"


// 결국 Client 개발자는 "ICalc.h", "CalcProxy.dll" 을 받아서
// 아래 처럼만 만들면 됩니다.

#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}







