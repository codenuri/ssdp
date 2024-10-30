#include <memory>
#include "ICalc.h"

int main()
{
	// C++ 표준에 있는 "std::shared_ptr" 을 사용하면 안되나요 ?

	std::shared_ptr<ICalc> p1( load_proxy() );
					// p1 의 소멸자에서 " delete " 합니다.
					// 결국 DLL 에서 new 한것을 exe 에서 delete 한것
					// 우리가 원하는 것은 delete 아니라 Release() 호출

	sp<ICalc> p2(load_proxy());
			// p2 는 소멸자에서 "보관된포인터->Release()" 호출
			// 즉, DLL 내부에서 delete!!!

	// 그래서, C++표준에 스마트포인터가 이미 있지만
	// 위와 같은 이유로, 많은 오픈소스가 자신만의 스마트 포인터를 만들어사용
}