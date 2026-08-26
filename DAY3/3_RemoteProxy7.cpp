#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = load_proxy();	

	calc1->AddRef();		// 규칙 #1. Proxy 처음 생성후 참조계수 증가

	ICalc* calc2 = calc1;
	calc2->AddRef();		// 규칙 #2. Proxy 포인터 복사후 참조계수 증가

	std::cout << calc1->Add(1, 2) << std::endl;

	// 규칙 #3. 포인터 사용후 참조계수 감소
	calc1->Release();

	std::cout << "----------------------\n";
	calc2->Release();
	std::cout << "----------------------\n";

}







