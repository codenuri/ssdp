#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = load_proxy();	

	calc1->AddRef();	// 규칙 #1. proxy 를 처음 만들면 참조계수 증가

	
	ICalc* calc2 = cacl1;
	calc2->AddRef();	// 규칙 #2. proxy 를 다른 포인터로 가리키게되면
						//			참조계수 증가

	calc2->Release();	// 규칙 #3. 더이상 사용하지 않으면 참조계수 감소

	std::cout << "----------------------\n";

	calc1->Release();	// 이때 참조계수 0 되므로 파괴 됩니다.

	std::cout << "----------------------\n";
}


