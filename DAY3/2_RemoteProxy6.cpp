#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	ICalc* calc1 = load_proxy();	

	calc1->AddRef();	// 규칙 #1. proxy 를 처음 만들면 참조계수 증가

	
	ICalc* calc2 = calc1;
	calc2->AddRef();	// 규칙 #2. proxy 를 다른 포인터로 가리키게되면
						//			참조계수 증가

	calc2->Release();	// 규칙 #3. 더이상 사용하지 않으면 참조계수 감소

	std::cout << "----------------------\n";

	calc1->Release();	// 이때 참조계수 0 되므로 파괴 됩니다.

	std::cout << "----------------------\n";


	// 위 코드는 어렵지는 않습니다. 그런데
	// 1. 관례적인 코드가 많고!!!
	// 2. 개발자가 실수 할수 있습니다.
	//		(AddRef, Release 호출을 실수로 생략하는 경우!!)

	// 실수 할수 없게 해 봅시다.
	// => 다음 단계!!!
	// => smart proxy 라는 개념 도입
}


