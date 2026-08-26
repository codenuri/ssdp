#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// RemoteProxy7.cpp
// => 어렵지는 않지만
// => 사용자가 직접 참조계수를 관리해야 하므로 "단순 코드의 반복"
// => 그리고, "실수 할수 있다" AddRef()/Release() 를 실수로 호출 안함

// 


int main()
{
	ICalc* calc1 = load_proxy();
	calc1->AddRef();		

	ICalc* calc2 = calc1;
	calc2->AddRef();		
	calc1->Release();
	calc2->Release();
}







