#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	// 결국 최종사용자는 아래 코드입니다.
	// => ICalc*  대신 sp<ICalc> 로만 변경

	sp<ICalc> calc1 = load_proxy(); 
	sp<ICalc> calc2 = calc1;

	int n1 = calc1->Add(1, 2);
	int n2 = calc2->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}




